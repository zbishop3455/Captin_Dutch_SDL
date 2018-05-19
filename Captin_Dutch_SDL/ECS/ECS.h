#pragma once

/*
	Entity Component System:
	- class Entity
	- class Component
	- class Manager

	System containing classes for enntity and component and a manager
*/


#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using Component_ID = std::size_t;

inline Component_ID get_component_type_ID()
{
	static Component_ID last_ID = 0;
	return last_ID++;
}


template <typename T> inline Component_ID get_component_type_ID() noexcept
{
	static Component_ID type_ID = get_component_type_ID();
	return type_ID;
}



// max number of componenets
constexpr std::size_t max_components = 32;

// bit set for determining which componenets an entity has
using ComponentBitSet = std::bitset<max_components>;
// Array of components 
using ComponentArray = std::array<Component*, max_components>;



// Base Component Class
class Componenet
{
public:

	virtual ~Componenet() {};

	virtual void init() {};
	virtual void draw() {};
	virtual void update() {};

	Entity * entity;
};



// Base Entity Class
class Entity
{
public:
	
	void update()
	{
		for (auto& c : components)
		{
			c->update();
		}

	}

	void draw()
	{
		for (auto& c : components)
		{
			c->draw();
		}
	}

	bool is_active() const
	{
		return active;
	}

	void destory()
	{
		active = false;
	}

	

	// HAS COMPONENT
	template <typename T> bool has_component() const
	{
		return componenet_bit_set[get_component_ID<T>];
	}



	// ADD COMPONENET
	//
	// variadic template method for adding components (takes variable amount of template arguments)
	template <typename T, typename... Template_Args>
	T& add_component(Template_Args&&... mArgs)
	{
		// create the comopnenents
		T* c(new T(std::forward<Template_Args>(mArgs)...));

		// set this entity to their owner
		c->entity = this;

		// place and register the component
		std::unique_ptr<Component> u_ptr{ c };
		components.emplace_back(std::move(u_ptr));

		// ensure the component type is placed in the same location in the component array
		component_array[get_component_type_ID<T>()] = c;
		componenet_bit_set[get_component_type_ID<T>()] = true;

		// initalize the component
		c->init();
		return *c;
	}



	// GET COMPONENT
	// usage: game_obj.get_component<Render_Component>().set_dst_rect(10);
	template <typename T>
	T& get_component() const
	{
		auto ptr(componenet_array[get_component_type_ID<T>()]);
		return static_cast<T*>(ptr);
	}



private:
	bool active = true;

	std::vector<std::unique_ptr<Componenet>> components;
	ComponentBitSet componenet_bit_set;
	ComponentArray componenet_array;
};



class Manager
{
public:

	void update()
	{
		for (auto& e : entities) e->draw();
	}

	void draw()
	{
		for (auto& e : entities) e->draw();
	}

	void refresh()
	{

		// remove entitiy if its not active
		entities.erase(
			std::remove_if(std::begin(entities),
			std::end(entities),
			[](const std::unique_ptr<Entity> &mEntity) { return !mEntity->is_active(); }),
			std::end(entities)
		);
	}

	Entity& add_entity()
	{
		Entity * e = new Entity();
		std::unique_ptr<Entity> u_ptr{ e };
		entities.emplace_back(std::move(u_ptr));
		return *e;
	}


private:
	std::vector<std::unique_ptr<Entity>> entities;
};

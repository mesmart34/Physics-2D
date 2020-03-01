#include "rigidbody.h"

rigidbody::rigidbody()
{
	//init();
}

rigidbody::~rigidbody()
{
	shutdown();
}

void rigidbody::init(vec2 position, float density, vec2* vertices, uint32_t vertices_count)
{
	shutdown();
	net_force = vec2();
	net_torque = 0.0f;
	velocity = vec2();
	this->position = position;
	this->vertices = vertices;
	this->vertices_count = vertices_count;
	set_density(density);
	angular_velocity = 0.0f;
	if (!is_static() || vertices_count > 4)
		set_angle(1.0f);
	else
		set_angle(0.0f);
}

void rigidbody::shutdown()
{
	if(vertices)
		delete[] vertices;
	vertices = NULL;
	vertices_count = 0;
}

void rigidbody::add_force(vec2 force)
{
	if (!is_static())
		net_force += force;
}

void rigidbody::add_force(vec2 force, vec2 p)
{
	if (is_static())
		return;
	net_force += force;
	net_torque += (p - position) ^ force;
}

void rigidbody::update(float dt)
{
	if (is_static())
	{
		velocity = vec2();
		angular_velocity = 0.0f;
		return;
	}
}

void rigidbody::set_angle(float angle)
{
	this->angle = angle;
}

void rigidbody::set_density(float density)
{
	mass = 0.0f;
	inv_mass = 0.0f;
	inertia = 0.0f;
	inv_inertia = 0.0f;
	this->density = density;

	if (density > 0.0f && vertices && vertices_count)
	{
		inv_mass = (mass > 0.0f) ? 1.0f / mass : 0.0f;
		inv_inertia = (inertia > 0.0f) ? 1.0f / inertia : 0.0f;
	}
}

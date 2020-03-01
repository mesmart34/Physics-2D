#pragma once
#include "vec2.h"
#include <stdint.h>

class rigidbody
{
public:
	rigidbody();
	~rigidbody();
	//rigidbody(const vec2)

	void init(vec2 position, float density, vec2 *vertices, uint32_t vertices_count);
	void shutdown();

	void add_force(vec2 force);
	void add_force(vec2 force, vec2 p);
	bool collides(rigidbody& rb, float dt);
	void update(float dt);
	void render() const;

	void set_angle(float angle);
	void set_density(float density);

	bool is_static() const { return mass < 0.001f; }
	vec2 get_position() const { return position; }
	vec2 get_velocity() const { return velocity; }
	float get_ang_velocity()const { return angular_velocity; }
	float get_mass() const { return mass; };
	float get_inv_mass() const { return inv_mass; }
	float get_inertia() const { return inertia; }
protected:
	void process_collision();
	void process_overlap();

	vec2 velocity;
	vec2 position;

	vec2* vertices;
	uint32_t vertices_count;

	float mass;
	float bouncing;
	float restriction;
	float density;
	float inertia;
	float inv_mass;
	float inv_inertia;

	float angle;
	float angular_velocity;

	vec2 net_force;
	float net_torque;
};
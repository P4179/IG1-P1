#pragma once

#include "../game/checkML.h"
#include "../structure/Entity.h"
#include "../structure/Manager.h"

namespace ecs {
	class Component {
	protected:
		ecs::Entity* ent_;
		ecs::Manager* mngr_;

		Component() : ent_(nullptr), mngr_(nullptr) {}

	public:

		// se utiliza para pasarle la entidad y el manager al que pertenece
		inline void setContext(ecs::Entity* ent, ecs::Manager* mngr) {
			ent_ = ent;
			mngr_ = mngr;
		}

		// se utiliza para inicializar los punteros a los componentes
		// que el puntero pueda utilizar
		virtual void initComponent() { }

		// manejar el update 
		virtual void update(float frameTime) = 0;

		// manejar el pintado
		virtual void render() = 0;

		// manejar el input
		virtual void handleInput(int key) = 0;
	};
}
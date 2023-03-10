#pragma once

#include "../game/checkML.h"
#include "../structure/Entity.h"
#include "../structure/Manager.h"

namespace ecs {
	class Component {
	protected:
		Entity* ent_;
		Manager* mngr_;

		Component() : ent_(nullptr), mngr_(nullptr) {} //Clase abstracta porque tiene la constructora en provado
		//no se puede hacer un new component, tan solo new de sus hijos

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
		virtual void update(float frameTime) = 0; //Poner aquí un =0 en vez de {} tambien nos indica que es una clase abstracta
		//Los hijos estaarías obligados a inicializar estos métodos. Para mayor comodidad se puede no poner = 0 y poner directamente {}
		//asi sus hijos no están obligados a redefinir estos 3 métodos

		// manejar el pintado
		virtual void render() = 0;

		// manejar el input
		virtual void handleInput(int key) = 0;
	};
}
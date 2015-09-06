#ifndef JUGADOR_H
#define JUGADOR_H 
#include "objeto.h"
#include "constantes.h"

const int ESTADO_PARADO = 0;
const int ESTADO_PARADO_FIN = 23;
const int ESTADO_CORRIENDO = ESTADO_PARADO_FIN + 1;
const int ESTADO_CORRIENDO_FIN = 47;
const int ESTADO_SALTANDO = ESTADO_CORRIENDO_FIN + 1;
const int ESTADO_SALTANDO_FIN = 57;
const int ESTADO_CAYENDO = ESTADO_SALTANDO_FIN + 1;
const int ESTADO_CAYENDO_FIN = 60;
const int ESTADO_CAYO = ESTADO_CAYENDO_FIN + 1;
const int ESTADO_CAYO_FIN = 67;
const int ESTADO_GOLPE = ESTADO_CAYO_FIN + 1;
const int ESTADO_GOLPE_FIN = 82;

class Jugador: public _2D::ObjetoMovil{
	private:
		static int automata[];
		static Imagen* automata_r[];

		int orientacion_;
	public:
		bool suelo;
		int estado_render;
		int orientacion();
		void izquierda();
		void derecha();
		void salto();
		void dibujar();
		void golpe();
		void iterar();
		bool estaCayendo();
		bool estaGolpeando();
		Jugador(const _2D::Rectangulo<double>& pos, Color f = Color::negro , const _2D::Punto<double> v = _2D::Punto<double>(), const _2D::Punto<double> a = _2D::Punto<double>()):_2D::ObjetoMovil(pos, GINTOKI_STAND1, f, v, a){
			orientacion_ = DERECHA;
			suelo = true;
			estado_render = 0;
			this->render = GINTOKI_STAND1;
		}

};

int Jugador::automata[]={
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,16,17,18,19,20,21,22,23,0,
	25,26,27,28, 29,30,31,32, 33,34,35,36, 37,38,39,40, 41,42,43,44, 45,46,47,24,
	49,50,51, 52,53,54, 55,56,57, 58,59, 60,57, 62,63,64,65,66,67,0,
	69,70,71,72,73,74,75,76,77,78,79,80,81,0
};

Imagen* Jugador::automata_r[]={
	GINTOKI_STAND1, // 0 
	GINTOKI_STAND1, // 1
	GINTOKI_STAND1, // 2
	GINTOKI_STAND1, // 3
	GINTOKI_STAND1, // 4
	GINTOKI_STAND2, // 5
	GINTOKI_STAND2, // 6
	GINTOKI_STAND2, // 7
	GINTOKI_STAND2, // 8
	GINTOKI_STAND2, // 9
	GINTOKI_STAND3, // 10
	GINTOKI_STAND3, // 11
	GINTOKI_STAND3, // 12
	GINTOKI_STAND3, // 13
	GINTOKI_STAND4, // 14
	GINTOKI_STAND4, // 15
	GINTOKI_STAND4, // 16
	GINTOKI_STAND4, // 17
	GINTOKI_STAND3, // 18
	GINTOKI_STAND3, // 19
	GINTOKI_STAND3, // 20
	GINTOKI_STAND2, // 21
	GINTOKI_STAND2, // 22
	GINTOKI_STAND2, // 23

	GINTOKI_PASO1,   // 24
	GINTOKI_PASO1,   // 25
	GINTOKI_PASO1,   // 26
	GINTOKI_PASO2,   // 27
	GINTOKI_PASO2,   // 28
	GINTOKI_PASO2,   // 29
	GINTOKI_PASO3,   // 30
	GINTOKI_PASO3,   // 31
	GINTOKI_PASO3,   // 32
	GINTOKI_PASO4,   // 33
	GINTOKI_PASO4,   // 34
	GINTOKI_PASO4,   // 35
	GINTOKI_PASO5,   // 36
	GINTOKI_PASO5,   // 37
	GINTOKI_PASO5,   // 38
	GINTOKI_PASO6,   // 39
	GINTOKI_PASO6,   // 40
	GINTOKI_PASO6,   // 41
	GINTOKI_PASO7,   // 42
	GINTOKI_PASO7,   // 43
	GINTOKI_PASO7,   // 44
	GINTOKI_PASO8,   // 45
	GINTOKI_PASO8,   // 46
	GINTOKI_PASO8,   // 47

	GINTOKI_SALTO1,  // 48
	GINTOKI_SALTO1,  // 49
	GINTOKI_SALTO1,  // 50
	GINTOKI_SALTO2,  // 51
	GINTOKI_SALTO2,  // 52
	GINTOKI_SALTO2,  // 53
	GINTOKI_SALTO3,  // 54
	GINTOKI_SALTO3,  // 55
	GINTOKI_SALTO3,  // 56
	
	GINTOKI_AIRE1,  // 57
	GINTOKI_AIRE1,  // 58
	GINTOKI_AIRE2,  // 59
	GINTOKI_AIRE2,  // 60

	GINTOKI_SUELO1, // 61
	GINTOKI_SUELO2, // 62
	GINTOKI_SUELO2, // 63
	GINTOKI_SUELO2, // 64
	GINTOKI_SUELO3, // 65
	GINTOKI_SUELO3, // 66
	GINTOKI_SUELO3, // 67

	GINTOKI_GOLPE1, //69
	GINTOKI_GOLPE1, //70
	GINTOKI_GOLPE2, //71
	GINTOKI_GOLPE2, //72
	GINTOKI_GOLPE3, //73
	GINTOKI_GOLPE3, //74
	GINTOKI_GOLPE4, //75
	GINTOKI_GOLPE4, //76
	GINTOKI_GOLPE5, //77
	GINTOKI_GOLPE5, //78
	GINTOKI_GOLPE6, //79
	GINTOKI_GOLPE6, //80
	GINTOKI_GOLPE7, //81
	GINTOKI_GOLPE7, //82


};

int Jugador::orientacion(){
	return orientacion_;
}

bool Jugador::estaCayendo(){
	return estado_render >= ESTADO_CAYO and estado_render <= ESTADO_CAYO_FIN;
}

bool Jugador::estaGolpeando(){
	return estado_render >= ESTADO_GOLPE and estado_render <= ESTADO_GOLPE_FIN;
}


void Jugador::izquierda(){
	if(estaCayendo() or estaGolpeando())
		return;
	if((estado_render > ESTADO_CORRIENDO_FIN or estado_render < ESTADO_CORRIENDO) and suelo){
		estado_render = ESTADO_CORRIENDO;
	}
	if(std::abs(this->velocidad.x-v_mov.x)<v_mov_max.x){
		this->velocidad.x-=v_mov.x;
	}

	orientacion_ = IZQUIERDA;
}

void Jugador::derecha(){
	if(estaCayendo() or estaGolpeando())
		return;
	if((estado_render > ESTADO_CORRIENDO_FIN or estado_render < ESTADO_CORRIENDO) and suelo){
		estado_render = ESTADO_CORRIENDO;
	}
	if(std::abs(this->velocidad.x+v_mov.x)<v_mov_max.x){
		this->velocidad.x+=v_mov.x;
	}

	this->orientacion_ = DERECHA;
}

void Jugador::salto(){
	if(estaCayendo() or estaGolpeando())
		return;
	if(suelo){	
		this->velocidad.y=v_salto.y;
		suelo = false;
		this->estado_render = ESTADO_SALTANDO;
	}
}

void Jugador::golpe(){
	if(suelo and not estaGolpeando()){
		this->velocidad = _2D::Punto<double>();
		this->estado_render = ESTADO_GOLPE;
	}
}

void Jugador::dibujar(){
	_2D::ObjetoMovil::dibujar(orientacion_ == IZQUIERDA);
	//std::cout<<suelo<<std::endl;
	estado_render = automata[estado_render];
	this->render = automata_r[estado_render];
}

void Jugador::iterar(){
	if((int)floor(0.5+velocidad.y)==0 and estado_render >= ESTADO_SALTANDO and estado_render <= ESTADO_CAYENDO_FIN and not suelo){
		suelo = true;
		estado_render = ESTADO_CAYO;
	}else if((int)floor(0.5+velocidad.norma())==0 and estado_render > ESTADO_PARADO_FIN and (estado_render < ESTADO_CAYO or estado_render > ESTADO_CAYO_FIN) and not estaGolpeando()){
		estado_render = ESTADO_PARADO;
	}else if((int)floor(0.5+velocidad.y) < 0 and (estado_render > ESTADO_CAYENDO_FIN or estado_render < ESTADO_CAYENDO)){
		estado_render = ESTADO_CAYENDO;
		suelo = false;
	}else if((int)floor(0.5+velocidad.x) != 0 and (estado_render > ESTADO_CORRIENDO_FIN or estado_render < ESTADO_CORRIENDO) and suelo){
		estado_render = ESTADO_CORRIENDO;
	}
	_2D::ObjetoMovil::iterar();
}
#endif
#include "Missile.h"


// Constructeur avec paramètres
Missile::Missile(float origineX, float origineY)
	: mPosition(origineX, origineY),
	mVelocity(),
	mAngularPos{},
	mAngularVel{},
	mMissileShot{}
{
	// Le vaisseau spatial aura la couleur noire, des traits blancs d'épaisseur de 1. Le point au centre
	// du vaisseau est à (0, 0).
	mShape.buildMissile(Color(1.0f, 1.0f, 0.0f, 1.0f), Color(0.0f, 0.0f, 0.0f, 1.0f), 0.0f, 0.0f);
}

// Destructeur
Missile::~Missile()
{
	// do nothing
}


// Accesseur(s) et mutateur(s) (fonctions membres)
Vect2d Missile::position() const
{
	return mPosition;
}

Vect2d Missile::velocity() const
{
	return mVelocity;
}

float Missile::angularPos() const
{
	return mAngularPos;
}

float Missile::angularVel() const
{
	return mAngularVel;
}

bool Missile::missileShot() const
{
	return mMissileShot;
}

void Missile::setPosition(Vect2d const& position)
{
	mPosition = position;
}

void Missile::setVelocity(Vect2d const& velocity)
{
	mVelocity = velocity;
}

void Missile::setAngularPos(float const& angularPos)
{
	mAngularPos = angularPos;
}

void Missile::setAngularVel(float const& angularVel)
{
	mAngularVel = angularVel;
}

void Missile::setMissileShot(bool const& missileShot)
{
	mMissileShot = missileShot;
}

// --------------------------------------------------------------------------------------
// Dessiner la forme polygonale dont le centre est au point mPosition
// Cette fonction membre est normalement exécutée après la MAJ de la position
// --------------------------------------------------------------------------------------

void Missile::processTime(float const& elapsedTime)
{
	mPosition += mVelocity * elapsedTime;
	mAngularPos += mAngularVel * elapsedTime;
}

void Missile::draw(ezapp::Screen& screen) const
{
	mShape.draw(screen, mPosition.x(), mPosition.y(), mAngularPos);
}

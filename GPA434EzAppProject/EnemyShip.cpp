/*  EnemyShip.cpp
 *  
 */
#include "EnemyShip.h"

 // Constructeur par défaut
EnemyShip::EnemyShip(Vect2d const& pos, Vect2d const& vel)
	: mPosition(pos), 
	mVelocity(vel), 
	mAngularPos{}, 
	mMissile(-1.0f, -1.0f),
	mShapeMissile(),
	vitesseMissile(-1, -1),
	mNbMissiles(1)
{
	mShape.buildEnemyShip(Color(0.0f, 0.0f, 1.0f, 0.0f), Color(0.0f, 0.0f, 0.0f, 1.0f), 0.0f, 0.0f);
	mShapeMissile.buildMissile(Color(0.6f, 1.0f, 0.0f, 1.0f), Color(0.0f, 0.0f, 0.0f, 1.0f), 0.0f, 0.0f);
}

// Destructeur
EnemyShip::~EnemyShip()
{
}

// --------------------------------------------------------------------------------------
// Accesseur(s) et mutateur(s) (fonctions membres)
// --------------------------------------------------------------------------------------
Vect2d EnemyShip::position() const
{
	return mPosition;
}

Vect2d EnemyShip::velocity() const
{
	return mVelocity;
}

float EnemyShip::angularPos() const
{
	return mAngularPos;
}

Vect2d EnemyShip::positionMissile() const
{
	// Retourner la position linéaire du missile
	return mMissile.position();
}

void EnemyShip::setPosition(Vect2d const& position)
{
	mPosition = position;
}

void EnemyShip::setVelocity(Vect2d const& velocity)
{
	mVelocity = velocity;
}

void EnemyShip::setAngularPos(float const& angularPos)
{
	mAngularPos = angularPos;
}

void EnemyShip::setPositionMissile(Vect2d const& position)
{
	mMissile.setPosition(position);
}

// --------------------------------------------------------------------------------------
// Régler aléatoirement les paramètres de l'astéroïde incluant sa forme polygonale
// Choisir des valeurs entre min et max pour les paramètres de l'astéroïde
// --------------------------------------------------------------------------------------
void EnemyShip::Create(float minPosX, float maxPosX, float minPosY,
	float maxPosY, float Vel)
{
	mPosition = Vect2d(random(minPosX, maxPosX), random(minPosY, maxPosY));
	mVelocity = Vel;

	mShape.buildEnemyShip(Color(0.0f, 0.0f, 1.0f, 0.0f), Color(0.0f, 0.0f, 0.0f, 1.0f), 0.0f, 0.0f);
}

// --------------------------------------------------------------------------------------
// Mise à jour de la position linéaire et angulaire de l'astéroïde
// Cette fonction membre est exécutée périodiquement par l'Engine du jeu.
//
// Note: Nouvelle position = vitesse x temps
// --------------------------------------------------------------------------------------
void EnemyShip::processTime(float const& elapsedTime)  // Update position vector
{
	mPosition += mVelocity * elapsedTime;
	mAngularPos = 0;
}

// --------------------------------------------------------------------------------------
// Dessiner la forme polygonale dont le centre est au point mPosition
// Cette fonction membre est normalement exécutée après la MAJ de la position
// --------------------------------------------------------------------------------------
void EnemyShip::draw(ezapp::Screen& screen) const
{
	mShape.draw(screen, mPosition.x(), mPosition.y(), mAngularPos);

}

void EnemyShip::resetVerticalPosition(float const& height)
{
	mPosition.setY(-height);
}

void EnemyShip::resetHorizontalPositionDown(float const& width)
{
	mPosition.setX(width);
}

// --------------------------------------------------------------------------------------
// Fonction membre privée pour générer un nombre aléatoire entre 0 et 1.
// --------------------------------------------------------------------------------------
float EnemyShip::random(float min, float max) const
{
	return (float)rand() / (float)RAND_MAX * (max - min) + min;
}

void EnemyShip::Aim(Spaceship& ship) 
{
	float angle = 3.141592654f / 2;

	angle += atan((ship.position().y() - mPosition.y()) / (ship.position().x() - mPosition.x()));

	if (ship.position().x() <= mPosition.x())
		angle += 3.141592654f;

	mAngularPos = angle;
}

void EnemyShip::Shoot(float const& elapsedTime)
{
	const float missileVel = 150.0f; // Module de la vitesse du missile

	// 1) Si la touche SPACEBAR est appuyée et que le missile est disponible à tirer...
	if (!mMissile.missileShot())//mMissile.missileShot() == false)
	{
		// 1.1) Règle l'état du missile à « tiré »
		mMissile.setMissileShot(true);

		// 1.2) Règle la position linéaire du missile (même que celle du vaisseau spatial)
		mMissile.setPosition(mPosition);  //mPosition du Spaceship?

		// 1.3) Règle la position angulaire du missile (même que celle du vaisseau spatial)
		mMissile.setAngularPos(mAngularPos); // AngPos du Spaceship?

		vitesseMissile.setFromPolar(missileVel, mMissile.angularPos() - (90.0f * 3.141592654f) / 180.0f);

		// 1.4) Calculer la vitesse du missile et l'assigner au missile
		mMissile.setVelocity(vitesseMissile);
	}
	// 2) Si le missile a été tiré
	if (mMissile.missileShot() == true)
	{
		// Alors mettre à jour la position du missile
		mMissile.processTime(elapsedTime);
	}
}

void EnemyShip::drawMissile(ezapp::Screen& screen) const
{
	mShapeMissile.draw(screen, mMissile.position().x(), mMissile.position().y(), mMissile.angularPos());
}

void Spaceship::collisionMissile()
{
	mMissile.collison();
	mNbMissiles = 1;
}
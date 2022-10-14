/*  Asteroid.h
 *  Cette classe g�re une forme polygonale repr�sentante un ast�ro�de. Voici les �l�ments
 *  g�r�s par elle:
 *    - Sa forme polygone qui est irr�guli�re;
 *    - Sa vitesse (lin�aire et angulaire);
 *    - Sa position (lin�aire et angulaire);
 *    - Se dessiner � l'�cran par le biais de la classe Polygon.
 *
 *  ------------------------------------------------------------------------------------------
 *  Techniques � �tudier
 *  ------------------------------------------------------------------------------------------
 *    - Comment g�rer la forme polygonale repr�sentant un ast�ro�de;
 *    - Donner � un ast�ro�de un comportement propre:
 *       i) il a une forme irr�guli�re d'o� l'utilisation de random();
 *      ii) il poss�de une vitesse initiale (lin�aire et angulaire) al�atoire.
 *  ------------------------------------------------------------------------------------------
 *
 *  Commentaires et modification par: T. Wong
 *  01-2021
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de donn�es: PascalCase
 *    Variables, fonctions: camelCase
 */
#pragma once
#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include "Vect2d.h"
#include "Polygon.h"
#include "Spaceship.h"
#include <EzApp>

class EnemyShip
{
public:
    EnemyShip(
        Vect2d const& pos = Vect2d(),
        Vect2d const& vel = Vect2d());
    ~EnemyShip();

    // Accesseur(s) et mutateur(s) (fonctions membres)
    Vect2d position() const;
    Vect2d velocity() const;
    float angularPos() const;
    Vect2d positionMissile() const;

    void setPosition(Vect2d const& position);
    void setVelocity(Vect2d const& velocity);
    void setAngularPos(float const& angularPos);
    void setPositionMissile(Vect2d const& position);

    // M�thodes (fonctions membres)
    void processTime(float const& elapsedTime);
    void draw(ezapp::Screen& screen) const;
    void drawMissile(ezapp::Screen& screen) const;

    void resetVerticalPosition(float const& height);
    void resetHorizontalPositionHop() { mPosition.setX(0.0f); }
    void resetHorizontalPositionDown(float const& width);

    void Create(float minPosX, float maxPosX, float minPosY,
        float maxPosY, float Vel);

    void Aim(Spaceship& ship);
    void Shoot(float const& elapsedTime);
    void collisionMissile();
    void collision(int screenWidth, int screenHeight);

private:
    Vect2d mPosition;          // position lin�aire
    Vect2d mVelocity;          // v�locity lin�aire
    Polygon mShape;            // forme polygonale
    float mAngularPos;         // position angulaire
    Missile mMissile;          // Missile
    Polygon mShapeMissile;
    Vect2d vitesseMissile;     // Vitesse du missile
    int mNbMissiles;

    // M�thode priv�e
    float random(float min, float max) const;
};

#endif //ENEMYSHIP_H
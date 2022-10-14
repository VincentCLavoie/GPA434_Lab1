/*  Asteroid.h
 *  Cette classe gère une forme polygonale représentante un astéroïde. Voici les éléments
 *  gérés par elle:
 *    - Sa forme polygone qui est irrégulière;
 *    - Sa vitesse (linéaire et angulaire);
 *    - Sa position (linéaire et angulaire);
 *    - Se dessiner à l'écran par le biais de la classe Polygon.
 *
 *  ------------------------------------------------------------------------------------------
 *  Techniques à étudier
 *  ------------------------------------------------------------------------------------------
 *    - Comment gérer la forme polygonale représentant un astéroïde;
 *    - Donner à un astéroïde un comportement propre:
 *       i) il a une forme irrégulière d'où l'utilisation de random();
 *      ii) il possède une vitesse initiale (linéaire et angulaire) aléatoire.
 *  ------------------------------------------------------------------------------------------
 *
 *  Commentaires et modification par: T. Wong
 *  01-2021
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de données: PascalCase
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

    // Méthodes (fonctions membres)
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
    Vect2d mPosition;          // position linéaire
    Vect2d mVelocity;          // vélocity linéaire
    Polygon mShape;            // forme polygonale
    float mAngularPos;         // position angulaire
    Missile mMissile;          // Missile
    Polygon mShapeMissile;
    Vect2d vitesseMissile;     // Vitesse du missile
    int mNbMissiles;

    // Méthode privée
    float random(float min, float max) const;
};

#endif //ENEMYSHIP_H
/*  Collision.cpp
 *  Cette classe est responsable de gérer les collisions entre les corps du jeu.
 *
 *  Pour cette étape:
 *    - Gérer les collision d'un astérïode avec les bordures de l'espace du jeu;
 *        i) Un astéroïde se déplace toujours du haut vers le bas;
 *       ii) On le renvoie à l'extérieur de la bordure supérieure à une distance égale à la
 *           hateur de l'espace du jeu lorqu'il dépasse la bordure inférieure;
 *      iii) On le renvoie à la bordure gauche de l'espace lorsqu'il dépasse la
 *           bordure droite et vice versa.
 *
 *  Commentaires et modification par: T. Wong
 *  01-2021
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de données: PascalCase
 *    Variables, fonctions: camelCase
 */
#pragma once
#ifndef COLLISION_H
#define COLLISION_H

#include <cmath>
#include "Asteroid.h"
#include "Spaceship.h" //$ Maybe remove later? -Vince

class Collision
{
public:
  Collision(float width, float height);
  ~Collision();

  // Accesseur(s) et mutateur(s) (fonctions membres)
  float width() const;
  float height() const;

  // Méthodes (fonctions membres)
  void collisionAsteroidWall(Asteroid& asteroid);
  void setCollisionAsteroide(bool const& collision);
  void CollisionOccured(bool collision);
  bool collisionAsteroide() const {
	  return mCollisionAsteroide;
  }
  void collisionSpaceshipWall(Spaceship& ship);
  void collisionMissileWall(Spaceship& ship);
  void collisionSpaceshipAsteroid(Spaceship& ship,
	  Asteroid const& asteroid);


private:
  float mWidth, mHeight;          // taille de l'espace du jeu
  bool mCollisionAsteroide;		  // indiquer qu'il y a eu collision    
};

#endif //COLLISION_H

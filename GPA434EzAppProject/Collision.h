/*  Collision.cpp
 *  Cette classe est responsable de g�rer les collisions entre les corps du jeu.
 *
 *  Pour cette �tape:
 *    - G�rer les collision d'un ast�r�ode avec les bordures de l'espace du jeu;
 *        i) Un ast�ro�de se d�place toujours du haut vers le bas;
 *       ii) On le renvoie � l'ext�rieur de la bordure sup�rieure � une distance �gale � la
 *           hateur de l'espace du jeu lorqu'il d�passe la bordure inf�rieure;
 *      iii) On le renvoie � la bordure gauche de l'espace lorsqu'il d�passe la
 *           bordure droite et vice versa.
 *
 *  Commentaires et modification par: T. Wong
 *  01-2021
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de donn�es: PascalCase
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

  // M�thodes (fonctions membres)
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

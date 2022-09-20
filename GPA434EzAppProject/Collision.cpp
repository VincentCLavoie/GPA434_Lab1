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
#include "Collision.h"

Collision::Collision(float width, float height)
    :mWidth(width),
     mHeight(height),
     mCollisionAsteroide { false }
{
}

Collision::~Collision()
{
    // do nothing
}

// --------------------------------------------------------------------------------------
// Accesseur(s) et mutateur(s) (fonctions membres)
// --------------------------------------------------------------------------------------
float Collision::width() const
{
  return mWidth;
}

float Collision::height() const
{
  return mHeight;
}


// --------------------------------------------------------------------------------------
// G�rer la collision entre un ast�ro�de et la bordure de l'espace du jeu
// --------------------------------------------------------------------------------------
void Collision::collisionAsteroidWall(Asteroid& asteroid)
{
    if (asteroid.position().y() >= mHeight)
        asteroid.resetVerticalPosition(mHeight);
    if (asteroid.position().x() >= mWidth)
        asteroid.resetHorizontalPositionHop();
    else if (asteroid.position().x() < 0.0f)
        asteroid.resetHorizontalPositionDown(mWidth);
}

void Collision::collisionSpaceshipWall(Spaceship& ship)
{
    // 1) G�rer la collision entre le vaisseau et la bordure inf�rieure.
    // 2) G�rer la collision entre le vaisseau et la bordure sup�rieure.
    // 3) G�rer la collision entre le vaisseau et la bordure droite.
    // 4) G�rer la collision entre le vaisseau et la bordure gauche.
}
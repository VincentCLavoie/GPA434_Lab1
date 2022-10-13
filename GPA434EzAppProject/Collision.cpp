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
    mCollisionAsteroide{ false }
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

void Collision::CollisionOccured(bool collision)
{
    mCollisionAsteroide = collision;
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
    if (ship.position().y() <= 0 || ship.position().y() >= mHeight)
        ship.collison();
    if (ship.position().x() <= 0 || ship.position().x() >= mWidth)
        ship.collison();
}

void Collision::collisionSpaceshipAsteroid(Spaceship& ship, Asteroid asteroid)
{
    // 1) Le rayon du cercle entourant le vaisseau et l'ast�ro�de.
    // Ajuster ces valeurs pour un meilleur r�sultat visuel.
    float rayonVaisseau = 30.0f, rayonAsteriod = 20.0f;

    // 2) Calculer la distance entre la position du vaisseau et l'ast�ro�de.
    // Si la distance est inf�rieure ou �gale � la somme des rayons alors il
    // y eu collision.

    // 2.1) R�gler mCollisionAsteroide pour indiquer qu'il y a eu collision
    // 2.2) Ex�cuter la fonction collision() du vaisseau spatial pour qu'il g�re
    // son comportement.

    float distance = sqrt(pow(ship.position().x() - asteroid.position().x(), 2) + pow(ship.position().y() - asteroid.position().y(), 2));
    if (distance <= rayonVaisseau + rayonAsteriod) {

        asteroid.randomize(5.0f, 20.0f, 0.0f, mWidth, -mHeight, -5.0f, 5.0f, 50.0f, 0.2f, 1.0f, 0.0f, 0.6f);

        mCollisionAsteroide = true;
        ship.collison();
    }
}

void Collision::collisionMissileWall(Spaceship& ship)
{
    if (ship.positionMissile().y() <= 0 || ship.positionMissile().y() >= mHeight)
        ship.collisionMissileWall();
    if (ship.positionMissile().x() <= 0 || ship.positionMissile().x() >= mWidth)
        ship.collisionMissileWall();
}

void Collision::collisionMissileAsteroid(Spaceship& ship, Asteroid asteroid)
{
    // 1) Le rayon du cercle entourant le vaisseau et l'ast�ro�de.
    // Ajuster ces valeurs pour un meilleur r�sultat visuel.
    float rayonMissile = 30.0f, rayonAsteriod = 20.0f;

    // 2) Calculer la distance entre la position du vaisseau et l'ast�ro�de.
    // Si la distance est inf�rieure ou �gale � la somme des rayons alors il
    // y eu collision.

    // 2.1) R�gler mCollisionAsteroide pour indiquer qu'il y a eu collision
    // 2.2) Ex�cuter la fonction collision() du vaisseau spatial pour qu'il g�re
    // son comportement.

    float distance = sqrt(pow(ship.positionMissile().x() - asteroid.position().x(), 2) + pow(ship.positionMissile().y() - asteroid.position().y(), 2));
    if (distance <= rayonMissile + rayonAsteriod) {
        asteroid.resetHorizontalPositionDown(mWidth);
        asteroid.resetVerticalPosition(mHeight);
        asteroid.resetHorizontalPositionHop();

        mCollisionAsteroide = true;
        ship.collison();
    }
}
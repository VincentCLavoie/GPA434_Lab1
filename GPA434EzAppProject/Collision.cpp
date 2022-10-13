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
// Gérer la collision entre un astéroïde et la bordure de l'espace du jeu
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
    // 1) Gérer la collision entre le vaisseau et la bordure inférieure.
    // 2) Gérer la collision entre le vaisseau et la bordure supérieure.
    // 3) Gérer la collision entre le vaisseau et la bordure droite.
    // 4) Gérer la collision entre le vaisseau et la bordure gauche.
    if (ship.position().y() <= 0 || ship.position().y() >= mHeight)
        ship.collison();
    if (ship.position().x() <= 0 || ship.position().x() >= mWidth)
        ship.collison();
}

void Collision::collisionSpaceshipAsteroid(Spaceship& ship, Asteroid asteroid)
{
    // 1) Le rayon du cercle entourant le vaisseau et l'astéroïde.
    // Ajuster ces valeurs pour un meilleur résultat visuel.
    float rayonVaisseau = 30.0f, rayonAsteriod = 20.0f;

    // 2) Calculer la distance entre la position du vaisseau et l'astéroïde.
    // Si la distance est inférieure ou égale à la somme des rayons alors il
    // y eu collision.

    // 2.1) Régler mCollisionAsteroide pour indiquer qu'il y a eu collision
    // 2.2) Exécuter la fonction collision() du vaisseau spatial pour qu'il gère
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
    // 1) Le rayon du cercle entourant le vaisseau et l'astéroïde.
    // Ajuster ces valeurs pour un meilleur résultat visuel.
    float rayonMissile = 30.0f, rayonAsteriod = 20.0f;

    // 2) Calculer la distance entre la position du vaisseau et l'astéroïde.
    // Si la distance est inférieure ou égale à la somme des rayons alors il
    // y eu collision.

    // 2.1) Régler mCollisionAsteroide pour indiquer qu'il y a eu collision
    // 2.2) Exécuter la fonction collision() du vaisseau spatial pour qu'il gère
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
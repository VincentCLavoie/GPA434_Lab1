/*  Spaceship.h
 *  Cette classe gère une forme polygonale représentante un viasseau spatial. Voici les éléments
 *  gérés par elle:
 *    - Sa forme polygone qui est particulière;
 *    - Sa vitesse (linéaire et angulaire);
 *    - Sa position (linéaire et angulaire);
 *    - Son accélération (linéaire et angulaire);
 *    - Sa distance parcourue;
 *    - Sa plus grande distance parcourue depuis le début du jeu;
 *    - Son dessin à l'écran par le biais de la classe Polygon.
 *
 *  ------------------------------------------------------------------------------------------
 *  GPA434 Laboratoire #1
 *  Cette classe est déjà réalisée en partie et les étudiants doit la compléter.
 *  ------------------------------------------------------------------------------------------
 *  Techniques à étudier
 *  ------------------------------------------------------------------------------------------
 *    - Comment construire la forme polygonale représentant le vaisseau spatial;
 *    - Donner à un vaisseau spatial un comportement propre.
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
#ifndef SPACESHIP_H
#define SPACESHIP_H


#include "Vect2d.h"
#include "Polygon.h"
#include "Missile.h"
#include <EzApp>

class Spaceship
{
public:
    Spaceship() = default;                    // constructeur par défaut
    Spaceship(float origineX, float origineY); // constructeur avec paramètre 
    ~Spaceship();                             // destructeur

    // Accesseur(s) et mutateur(s) (fonctions membres)
    Vect2d position() const;
    Vect2d velocity() const;
    Vect2d acceleration() const;
    float angularPos() const;
    float angularVel() const;
    float angularAcc() const;
    float distanceMade() const;
    int nbMissiles() const;

    void setPosition(Vect2d const& position);
    void setVelocity(Vect2d const& velocity);
    void setAcceleration(Vect2d const& acceleration);
    void setAngularPos(float const& angularPos);
    void setAngularVel(float const& angularVel);
    void setAngularAcc(float const& angularAcc);
    void resetAngularAcc();
    void resetDistanceMade();
    void resetSpaceship(float const& width, float const& height);
    void setNbMissiles(int nbMissiles);

    Vect2d positionMissile() const;

    // --------------------------------------------------------------------------
    // Méthodes pour la mise à jour de:
    //    - la position linéaire et angulaire;
    //    - la distance parcourie.
    // Méthode pour gérer la collision avec un astéroïde.
    // --------------------------------------------------------------------------
    void processTime(float const& elapsedTime);
    void angularProcessTime(float const& elapsedTime);
    void distanceMade(float const& elapsedTime);
    void collison();

    // --------------------------------------------------------------------------
    // Méthodes pour faire le traçage sur le canvas (écran) EzApp:
    //    - la forme polygonale;
    //    - la distance parcourue;
    //    -Écran de fin
    //    - la plus grande distance parcourue.
    // --------------------------------------------------------------------------
    void draw(ezapp::Screen& screen) const;
    void drawDistanceMade(ezapp::Screen& screen) const;
    void drawGameOverScreen(ezapp::Screen& screen) const;
    void drawBestDistance(ezapp::Screen& screen) const;

    // --------------------------------------------------------------------------
    // Méthodes pour changer la position du vaisseau spatial
    // --------------------------------------------------------------------------
    void resetVerticalPositionHop() { mPosition.setY(0.0f); }
    void resetVerticalPositionDown(float const& height);
    void resetHorizontalPositionHop() { mPosition.setX(0.0f); }
    void resetHorizontalPositionDown(float const& width);
    bool missileShot() const; //
    void resetMissileShot(bool const& missileShot);
    void manageMissile(bool const& spaceBarPressed, float const& elapsedTime);
    void drawMissile(ezapp::Screen& screen) const;
    void drawNbMissile(ezapp::Screen& screen) const;
    void collisionMissile();

private:

    Vect2d mPosition;          // position linéaire
    Vect2d mVelocity;          // vitesse linéaire
    Vect2d mAcceleration;      // accélération (en X et en Y)
    float mAngularPos;         // position angulaire
    float mAngularVel;         // vitesse angulaire
    float mAngularAcc;         // accélération angulaire
    float mDistanceMade;       // distance parcourue (en pixels)
    float mBestDistance;       // plus grande distance parcourue
    Polygon mShape;            // forme polygonale du vaisseau
    Polygon mShapeMissile;
    Missile mMissile;
    Vect2d vitesseMissile;     // Vitesse du missile
    int mNbMissiles;

};
#endif //SPACESHIP_H
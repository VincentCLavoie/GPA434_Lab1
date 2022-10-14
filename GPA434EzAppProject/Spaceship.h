/*  Spaceship.h
 *  Cette classe g�re une forme polygonale repr�sentante un viasseau spatial. Voici les �l�ments
 *  g�r�s par elle:
 *    - Sa forme polygone qui est particuli�re;
 *    - Sa vitesse (lin�aire et angulaire);
 *    - Sa position (lin�aire et angulaire);
 *    - Son acc�l�ration (lin�aire et angulaire);
 *    - Sa distance parcourue;
 *    - Sa plus grande distance parcourue depuis le d�but du jeu;
 *    - Son dessin � l'�cran par le biais de la classe Polygon.
 *
 *  ------------------------------------------------------------------------------------------
 *  GPA434 Laboratoire #1
 *  Cette classe est d�j� r�alis�e en partie et les �tudiants doit la compl�ter.
 *  ------------------------------------------------------------------------------------------
 *  Techniques � �tudier
 *  ------------------------------------------------------------------------------------------
 *    - Comment construire la forme polygonale repr�sentant le vaisseau spatial;
 *    - Donner � un vaisseau spatial un comportement propre.
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
#ifndef SPACESHIP_H
#define SPACESHIP_H


#include "Vect2d.h"
#include "Polygon.h"
#include "Missile.h"
#include <EzApp>

class Spaceship
{
public:
    Spaceship() = default;                    // constructeur par d�faut
    Spaceship(float origineX, float origineY); // constructeur avec param�tre 
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
    // M�thodes pour la mise � jour de:
    //    - la position lin�aire et angulaire;
    //    - la distance parcourie.
    // M�thode pour g�rer la collision avec un ast�ro�de.
    // --------------------------------------------------------------------------
    void processTime(float const& elapsedTime);
    void angularProcessTime(float const& elapsedTime);
    void distanceMade(float const& elapsedTime);
    void collison();

    // --------------------------------------------------------------------------
    // M�thodes pour faire le tra�age sur le canvas (�cran) EzApp:
    //    - la forme polygonale;
    //    - la distance parcourue;
    //    -�cran de fin
    //    - la plus grande distance parcourue.
    // --------------------------------------------------------------------------
    void draw(ezapp::Screen& screen) const;
    void drawDistanceMade(ezapp::Screen& screen) const;
    void drawGameOverScreen(ezapp::Screen& screen) const;
    void drawBestDistance(ezapp::Screen& screen) const;

    // --------------------------------------------------------------------------
    // M�thodes pour changer la position du vaisseau spatial
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

    Vect2d mPosition;          // position lin�aire
    Vect2d mVelocity;          // vitesse lin�aire
    Vect2d mAcceleration;      // acc�l�ration (en X et en Y)
    float mAngularPos;         // position angulaire
    float mAngularVel;         // vitesse angulaire
    float mAngularAcc;         // acc�l�ration angulaire
    float mDistanceMade;       // distance parcourue (en pixels)
    float mBestDistance;       // plus grande distance parcourue
    Polygon mShape;            // forme polygonale du vaisseau
    Polygon mShapeMissile;
    Missile mMissile;
    Vect2d vitesseMissile;     // Vitesse du missile
    int mNbMissiles;

};
#endif //SPACESHIP_H
/*  Missile.h
 *  Cette classe gère un missile qui est tiré par le vaisseau spatial. Voici les éléments
 *  gérés par elle:
 *    - Sa forme polygone qui est particulière;
 *    - Sa vitesse (linéaire et angulaire);
 *    - Sa position (linéaire et angulaire);
 *    - Son état: tiré ou non tiré;
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
#ifndef MISSILE_H
#define MISSILE_H

#include "Vect2d.h"
#include "Polygon.h"
#include <EzApp>


class Missile
{
public:
    Missile(float origineX, float origineY);       // constructeur par défaut
    ~Missile();      // destructeur

    // Accesseur(s) et mutateur(s) (fonctions membres)
    Vect2d position() const;
    Vect2d velocity() const;
    float angularPos() const;
    float angularVel() const;
    bool missileShot() const;

    void setPosition(Vect2d const& position);
    void setVelocity(Vect2d const& velocity);
    void setAngularPos(float const& angularPos);
    void setAngularVel(float const& angularVel);
    void setMissileShot(bool const& missileShot);

    // --------------------------------------------------------------------------
    // Méthode pour la mise à jour de:
    //    - la position linéaire et angulaire;
    //    - la distance parcourie.
    // Méthode pour le dessin du missile à l'écran 
    // --------------------------------------------------------------------------
    void processTime(float const& elapsedTime);
    void draw(ezapp::Screen& screen) const;
    void collison();

private:
    Vect2d mPosition;          // Pposition linéaire
    Vect2d mVelocity;          // vitesse linéaire
    float mAngularPos;         // position angulaire
    float mAngularVel;         // vitesse angulaire
    Polygon mShape;            // forme polygonale du missile
    bool mMissileShot;         // missile tiré ou non 

};

#endif //MISSILE_H

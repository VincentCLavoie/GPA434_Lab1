/*  MissileGuidé.h
*
 *  Cette classe gère un missile guidé qui est tiré par le vaisseau spatial. Voici les éléments
 *  gérés par elle:
 *    - Sa forme polygone qui est particulière;
 *    - Sa vitesse (linéaire et angulaire);
 *    - Sa position (linéaire et angulaire);
 *    - Son état: tiré ou non tiré;
 *    - Son dessin à l'écran par le biais de la classe Polygon.
 *
 *
 *
 *  Commentaires et modification par: Russel Jin
 *  10-2022
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de données: PascalCase
 *    Variables, fonctions: camelCase
 */
#pragma once
#ifndef MISSILEGUIDE_H
#define MISSILEGUIDE_H

#include "Vect2d.h"
#include "Polygon.h"
#include <EzApp>


class MissileGuide
{
public:
    MissileGuide(float origineX, float origineY);   // constructeur par défaut
    ~MissileGuide();                                // destructeur

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

#endif //MISSILEGUIDE_H
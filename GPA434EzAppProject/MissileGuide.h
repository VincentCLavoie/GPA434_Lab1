/*  MissileGuid�.h
*
 *  Cette classe g�re un missile guid� qui est tir� par le vaisseau spatial. Voici les �l�ments
 *  g�r�s par elle:
 *    - Sa forme polygone qui est particuli�re;
 *    - Sa vitesse (lin�aire et angulaire);
 *    - Sa position (lin�aire et angulaire);
 *    - Son �tat: tir� ou non tir�;
 *    - Son dessin � l'�cran par le biais de la classe Polygon.
 *
 *
 *
 *  Commentaires et modification par: Russel Jin
 *  10-2022
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de donn�es: PascalCase
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
    MissileGuide(float origineX, float origineY);   // constructeur par d�faut
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
    // M�thode pour la mise � jour de:
    //    - la position lin�aire et angulaire;
    //    - la distance parcourie.
    // M�thode pour le dessin du missile � l'�cran 
    // --------------------------------------------------------------------------
    void processTime(float const& elapsedTime);
    void draw(ezapp::Screen& screen) const;
    void collison();

private:
    Vect2d mPosition;          // Pposition lin�aire
    Vect2d mVelocity;          // vitesse lin�aire
    float mAngularPos;         // position angulaire
    float mAngularVel;         // vitesse angulaire
    Polygon mShape;            // forme polygonale du missile
    bool mMissileShot;         // missile tir� ou non 

};

#endif //MISSILEGUIDE_H
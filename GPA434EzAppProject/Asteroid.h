/*  Asteroid.h
 *  Cette classe gère une forme polygonale représentante un astéroïde. Voici les éléments
 *  gérés par elle:
 *    - Sa forme polygone qui est irrégulière;
 *    - Sa vitesse (linéaire et angulaire);
 *    - Sa position (linéaire et angulaire);
 *    - Se dessiner à l'écran par le biais de la classe Polygon.
 *
 *  ------------------------------------------------------------------------------------------
 *  Techniques à étudier
 *  ------------------------------------------------------------------------------------------
 *    - Comment gérer la forme polygonale représentant un astéroïde;
 *    - Donner à un astéroïde un comportement propre:
 *       i) il a une forme irrégulière d'où l'utilisation de random();
 *      ii) il possède une vitesse initiale (linéaire et angulaire) aléatoire.
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
#ifndef ASTEROID_H
#define ASTEROID_H


#include "Vect2d.h"
#include "Polygon.h"
#include <EzApp>

class Asteroid
{
public:
  Asteroid(float const& nbVertex = 5.0f,    // constructeur par défaut
           Vect2d const& pos = Vect2d(),
           Vect2d const& vel = Vect2d(),
           float const& angVel = 1.0f,
           float const& fillGrey = 0.0f);
  Asteroid(float minNbVertex, float maxNbVertex, // constructeur avec paramètres
           float minPosX, float maxPosX,
           float minPosY, float maxPosY,
           float minVel, float maxVel,
           float minAngVel, float maxAngVel,
           float minGrey, float maxGrey); 
  ~Asteroid();

  // Accesseur(s) et mutateur(s) (fonctions membres)
  Vect2d position() const;
  Vect2d velocity() const;
  float angularPos() const;
  float angularVel() const;
  float nbVertex() const;

  void setPosition(Vect2d const& position);
  void setVelocity(Vect2d const& velocity);
  void setAngularPos(float const& angularPos);
  void setAngularVel(float const& angularVel);
  void setNbVertex(float const& nbSummut);

  // Méthodes (fonctions membres)
  void processTime(float const& elapsedTime);
  void draw(ezapp::Screen& screen) const;
  
  void resetVerticalPosition(float const& height);
  void resetHorizontalPositionHop() { mPosition.setX(0.0f); }
  void resetHorizontalPositionDown(float const& width);

  void randomize(float minNbVertex, float maxNbVertex,
      float minPosX, float maxPosX,
      float minPosY, float maxPosY,
      float minVel, float maxVel,
      float minAngVel, float maxAngVel,
      float minGrey, float maxGrey);

private:
  Vect2d mPosition;          // position linéaire
  Vect2d mVelocity;          // vélocity linéaire
  Polygon mShape;            // forme polygonale de l'astéroïde
  float mAngularPos;         // position angulaire
  float mAngularVel;         // vélocité angulaire
  float mNbVertex;           // nombre de sommets dans la forme
  float mFillGrey;           // couleur de la forme
  // Méthode privée
  float random(float min, float max) const;
};



#endif //ASTEROID_H


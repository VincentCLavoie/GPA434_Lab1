/*  GameEngine.h
 *  Cette classe rerpésente le coordonnateur du jeu (Game Engine).
 *
 *  Pour cette étape, le coordonnateur est en mesure de coordonner:
 *    - le déplacement des astéroïdes dans l'espace du jeu;
 *    - l'affichage des astérpïdes dans l'espace du jeu.
 *
 *  ------------------------------------------------------------------------------------------
 *  Techniques à étudier
 *  ------------------------------------------------------------------------------------------
 *    - Comment parcourir un vecteur contenant des objets astéroïdes
 *    - Comment initialiser les objets astéroïdes.
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
#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <EzApp>
#include "Collision.h"
#include "Asteroid.h"


class GameEngine
{
public:
  GameEngine(float width = 800, float height = 600);  // constructeur par défaut
  ~GameEngine();                                      // destructeur
  GameEngine(const GameEngine& p) = delete;           // constructeur de copie
  GameEngine& operator=(const GameEngine& c) = delete;// constructeur par assignation

  // Méthodes (fonctions membres)
  // Note: Ces deux méthodes seront exécutées par EzApp à chaque pas de temps (time step)
  //       Aussi, la signature et le type de retour de ces fonctions membres sont imposées
  //       par la bibliothèque EzApp.
  bool processEvents(ezapp::Keyboard const& keyboard, ezapp::Timer const& timer);
  void processDisplay(ezapp::Screen& screen);

private:
  float mWidth, mHeight;             // taille de l'espace du jeu
  Color mBackgroundColor;            // couleur de fond de l'espace du jeu
  std::vector<Asteroid> mAsteroid;   // des astéroïdes
  Collision mCollision;              // gestion des collisions
   
};

#endif //GAME_ENGINE_H
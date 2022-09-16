/*  GameEngine.h
 *  Cette classe rerp�sente le coordonnateur du jeu (Game Engine).
 *
 *  Pour cette �tape, le coordonnateur est en mesure de coordonner:
 *    - le d�placement des ast�ro�des dans l'espace du jeu;
 *    - l'affichage des ast�rp�des dans l'espace du jeu.
 *
 *  ------------------------------------------------------------------------------------------
 *  Techniques � �tudier
 *  ------------------------------------------------------------------------------------------
 *    - Comment parcourir un vecteur contenant des objets ast�ro�des
 *    - Comment initialiser les objets ast�ro�des.
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
#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <EzApp>
#include "Collision.h"
#include "Asteroid.h"


class GameEngine
{
public:
  GameEngine(float width = 800, float height = 600);  // constructeur par d�faut
  ~GameEngine();                                      // destructeur
  GameEngine(const GameEngine& p) = delete;           // constructeur de copie
  GameEngine& operator=(const GameEngine& c) = delete;// constructeur par assignation

  // M�thodes (fonctions membres)
  // Note: Ces deux m�thodes seront ex�cut�es par EzApp � chaque pas de temps (time step)
  //       Aussi, la signature et le type de retour de ces fonctions membres sont impos�es
  //       par la biblioth�que EzApp.
  bool processEvents(ezapp::Keyboard const& keyboard, ezapp::Timer const& timer);
  void processDisplay(ezapp::Screen& screen);

private:
  float mWidth, mHeight;             // taille de l'espace du jeu
  Color mBackgroundColor;            // couleur de fond de l'espace du jeu
  std::vector<Asteroid> mAsteroid;   // des ast�ro�des
  Collision mCollision;              // gestion des collisions
   
};

#endif //GAME_ENGINE_H
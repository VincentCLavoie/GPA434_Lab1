/*  GameEngine.cpp
 *  Cette classe rerpésente le coordonnateur du jeu (Game Engine). Le coordonnateur est
 *  responsable d'exécuter les activités d'un pas de temps (time step) du jeu.
 *
 *  Pour cette étape, le coordonnateur est en mesure de coordonner:
 *    - le déplacement des astéroïdes dans l'espace du jeu;
 *    - l'affichage des astéroïdes dans l'espace du jeu.
 *    - la gestion des collisions (par le biais d'un objet de la classe Collision)
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
#include "GameEngine.h"

// Constructeur par défaut
GameEngine::GameEngine(float width, float height)
    :mWidth{ width },             // largeur du jeu
    mHeight{ height },            // hauteur du jeu
    mBackgroundColor(0.34f, 0.45f, 0.56f, 1.0f), // couleur de fond
    // pour choisir une couleur: https://www.tug.org/pracjourn/2007-4/walden/color.pdf
    mAsteroid(20),                // créer 20 astéroïdes
    mCollision(mWidth,mHeight)    // indiquer la taille du jeu au gestionnaire des collisions
{
  // 
  for (auto& Asteroid : mAsteroid) {
    // Pour chaque astéroïde initialiser ses paramètres par un choix aléatoire entre min et max:
    //  - Nombre de sommets (5 à 20);
    //  - Position initiale X (toute la largeur du canvas) et Y (vertical en dehors du canvas);
    //  - Vélocité linéaire (5 à 50);
    //  - Vélocité angulaire (0.2 à 1);
    //  - Couleur (Note: Niveau de gris pour un astéroïde).
    //
    // Note: Pour ces paramètres expérimenter avec différentes valeurs.
    Asteroid.randomize(5.0f, 20.0f, 0.0f, width, -height, -5.0f, 5.0f, 50.0f,0.2f,1.0f, 0.0f, 0.6f);
  }
}

// Destructeur
GameEngine::~GameEngine()
{
  // do nothing
}

// --------------------------------------------------------------------------------------
// Traiter les évènements (actions) en implantant la logique du jeu.
//
// Pour cette étape:
//    - Faire avance un pas de temps les astéroïdes;
//    - Gérer les collisions entre les astéroïdes et les bordures de l'espace du jeu.
// --------------------------------------------------------------------------------------
bool GameEngine::processEvents(ezapp::Keyboard const& keyboard, ezapp::Timer const& timer)
{ 
  // À implanter (voir le document "GPA434_Lab1_Démarrage_Rapide.pdf")
  return !keyboard.isKeyPressed(ezapp::Keyboard::Key::Escape);
}


// --------------------------------------------------------------------------------------
// Tracer les corps selon leur position et la direction actuelle. Le traçage s'effectue
// sur le canvas (écran) de EzApp.
//
// Pour cette étape:
//    - Tracer les astéroïdes.
//
// Note: Cette fonction membre est exécutée par EzApp après la mise à jour des corps.
// --------------------------------------------------------------------------------------
void GameEngine::processDisplay(ezapp::Screen& screen)
{
  // À implanter (voir le document "GPA434_Lab1_Démarrage_Rapide.pdf")
}



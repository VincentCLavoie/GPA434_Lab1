/*  main.cpp
 *  Programme principal du jeu.
 *  
 *  ------------------------------------------------------------------------------------------
 *  Pour cette �tape:
 *   - Initialiser l'environnement du jeu. Il faut donc ma�triser les services de EzApp;
 *   - Faire afficher des ast�ro�des et les faire d�placer dans le canvas (�cran EzApp);
 *   - G�rer les collisions entre les ast�ro�des et les bordures du canvas.
 *  ------------------------------------------------------------------------------------------
 *  Note: pour sortir du jeu appuyer sur la touche ESC.
 *  ------------------------------------------------------------------------------------------
 * 
 *  Commentaires et modification par: T. Wong
 *  01-2021
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de donn�es: PascalCase
 *    Variables, fonctions: camelCase
 */
#include "GameEngine.h"

// Fonction principale
int WinMain() 
{
  // Define default parameters
  size_t const windowWidth{ 1280 };  
  size_t const windowHeight{ 720 };  
  std::string const title("GPA434 Projet 1");
  std::string const iconFilename("GPALogo.png");
  std::list<std::string> const fontFilename({ "Arial" });

  // Define main application and setup parameters
  ezapp::Application app(ezapp::Application::Parameters(windowWidth, windowHeight, title, iconFilename, fontFilename));

  // Define Game
  GameEngine gameEngine(windowWidth, windowHeight);

  // Run application
  app.run(gameEngine, &GameEngine::processEvents, &GameEngine::processDisplay);

  // End the program
  return 0;
}

//CECI EST UN TEST SVP EFFACER -VIncenT

//TEST2 ordi liliam
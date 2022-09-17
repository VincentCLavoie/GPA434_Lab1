/*  GameEngine.cpp
 *  Cette classe rerp�sente le coordonnateur du jeu (Game Engine). Le coordonnateur est
 *  responsable d'ex�cuter les activit�s d'un pas de temps (time step) du jeu.
 *
 *  Pour cette �tape, le coordonnateur est en mesure de coordonner:
 *    - le d�placement des ast�ro�des dans l'espace du jeu;
 *    - l'affichage des ast�ro�des dans l'espace du jeu.
 *    - la gestion des collisions (par le biais d'un objet de la classe Collision)
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
#include "GameEngine.h"

// Constructeur par d�faut
GameEngine::GameEngine(float width, float height)
    :mWidth{ width },             // largeur du jeu
    mHeight{ height },            // hauteur du jeu
    mBackgroundColor(0.34f, 0.45f, 0.56f, 1.0f), // couleur de fond
    // pour choisir une couleur: https://www.tug.org/pracjourn/2007-4/walden/color.pdf
    mAsteroid(20),                // cr�er 20 ast�ro�des
    mCollision(mWidth,mHeight)    // indiquer la taille du jeu au gestionnaire des collisions
{
  // 
  for (auto& Asteroid : mAsteroid) {
    // Pour chaque ast�ro�de initialiser ses param�tres par un choix al�atoire entre min et max:
    //  - Nombre de sommets (5 � 20);
    //  - Position initiale X (toute la largeur du canvas) et Y (vertical en dehors du canvas);
    //  - V�locit� lin�aire (5 � 50);
    //  - V�locit� angulaire (0.2 � 1);
    //  - Couleur (Note: Niveau de gris pour un ast�ro�de).
    //
    // Note: Pour ces param�tres exp�rimenter avec diff�rentes valeurs.
    Asteroid.randomize(5.0f, 20.0f, 0.0f, width, -height, -5.0f, 5.0f, 50.0f,0.2f,1.0f, 0.0f, 0.6f);
  }
}

// Destructeur
GameEngine::~GameEngine()
{
  // do nothing
}

// --------------------------------------------------------------------------------------
// Traiter les �v�nements (actions) en implantant la logique du jeu.
//
// Pour cette �tape:
//    - Faire avance un pas de temps les ast�ro�des;
//    - G�rer les collisions entre les ast�ro�des et les bordures de l'espace du jeu.
// --------------------------------------------------------------------------------------
bool GameEngine::processEvents(ezapp::Keyboard const& keyboard, ezapp::Timer const& timer)
{ 
    // S'il y a lieu, g�rer les corps avant les ast�ro�des
    
    // G�rer les ast�ro�des
    for (auto& Asteroid : mAsteroid) {
        Asteroid.processTime(timer.secondSinceLastTic());
        mCollision.collisionAsteroidWall(Asteroid);
    }

    // S'il y a lieu, g�rer les corps apr�s les ast�ro�des
    
    // Retourner false si l'utilisateur a appuy� sur la touche ESC
    // afin d'arr�ter le jeu.
    return !keyboard.isKeyPressed(ezapp::Keyboard::Key::Escape);
}


// --------------------------------------------------------------------------------------
// Tracer les corps selon leur position et la direction actuelle. Le tra�age s'effectue
// sur le canvas (�cran) de EzApp.
//
// Pour cette �tape:
//    - Tracer les ast�ro�des.
//
// Note: Cette fonction membre est ex�cut�e par EzApp apr�s la mise � jour des corps.
// --------------------------------------------------------------------------------------
void GameEngine::processDisplay(ezapp::Screen& screen)
{
    screen.setBrush(mBackgroundColor.red(), mBackgroundColor.green(),
        mBackgroundColor.blue(), mBackgroundColor.alpha());
    screen.clear();
    // S'il y a lieu, tracer les �l�ments/corps avant les ast�ro�des
    // Tracer les ast�ro�des sur le canvas (�cran) de EzApp
    for (auto& Asteroid : mAsteroid) {
        Asteroid.draw(screen);
    }
    // S'il y a lieu, tracer les �l�ments/corps apr�s les ast�ro�des
    
    // Afficher un message expliquant cette �tape (� enlever dans la version
    // finale du jeu)
    Polygon message;
    std::string msg = "�tape 1: D�placement des ast�ro�des";
    message.setColors(Color(1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f));
    message.drawText(screen, msg, 20.0f, 35.0f, 0.0f, 0.7f);
}



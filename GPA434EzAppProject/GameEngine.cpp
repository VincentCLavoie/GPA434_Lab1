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
    mEnemyShip(1),
    mShip(width / 2, height / 2),   // le vaisseau spatial au centre du jeu
    mCollision(mWidth, mHeight),    // indiquer la taille du jeu au gestionnaire des collisions
    mState(false)
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
        Asteroid.randomize(5.0f, 20.0f, 0.0f, width, -height, -5.0f, 5.0f, 50.0f, 0.2f, 1.0f, 0.0f, 0.6f);
    }

    for (auto& EnemyShip : mEnemyShip) {
        EnemyShip.Create(400, 400, 400, 400, 0);
    }
}

// Destructeur
GameEngine::~GameEngine()
{
    // do nothing
}

void GameEngine::setState(bool const& state)
{
    mState = state;
}

bool GameEngine::state() const
{
    return mState;
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
    bool finDeJeu = false;

    if (state() == false)
    {
        finDeJeu = true;

        if (keyboard.isKeyPressed(ezapp::Keyboard::Key::P))
        {
            setState(true);
        }

        // Retourner false si l'utilisateur a appuyé sur la touche ESC
        // afin d'arrêter le jeu.
        return !keyboard.isKeyPressed(ezapp::Keyboard::Key::Escape);

    }

    // S'il y a lieu, gérer les corps avant les astéroïdes

    // Gérer les astéroïdes
    for (auto& Asteroid : mAsteroid) {
        Asteroid.processTime(timer.secondSinceLastTic());
        mCollision.collisionAsteroidWall(Asteroid);
    }

    // Gérer les vaisseau adverssaires
    for (auto& EnemyShip : mEnemyShip) {
        EnemyShip.processTime(timer.secondSinceLastTic());
        EnemyShip.Aim(mShip);
        EnemyShip.Shoot(timer.secondSinceLastTic());
    }

    const float m = 100.0f; const float c = 50.0f;
    Vect2d acceleration(0.0f, 0.0f); float angularAcc(0.0f);


    // 1) RAZ le jeu s'il y a eu collision entre le vaisseau et un astéroïde et
    // que le joueur a appuyé sur la touche ENTER.
    if (mCollision.collisionAsteroide())
    {

        // 1.3) Mettre Collision::mCollisionAsteroide à false
        if (keyboard.isKeyPressed(ezapp::Keyboard::Key::Space))
        {
            // 1.1) Repositionner aléatoirement les astéroïdes.
            for (auto& Asteroid : mAsteroid) {
                // Pour chaque astéroïde initialiser ses paramètres par un choix aléatoire entre min et max:
                //  - Nombre de sommets (5 à 20);
                //  - Position initiale X (toute la largeur du canvas) et Y (vertical en dehors du canvas);
                //  - Vélocité linéaire (5 à 50);
                //  - Vélocité angulaire (0.2 à 1);
                //  - Couleur (Note: Niveau de gris pour un astéroïde).
                //
                // Note: Pour ces paramètres expérimenter avec différentes valeurs.
                Asteroid.randomize(5.0f, 20.0f, 0.0f, mWidth, -mHeight, -5.0f, 5.0f, 50.0f, 0.2f, 1.0f, 0.0f, 0.6f);
            }
            // 1.2) Repositionner le corps contrôlable au centre du jeu.
            mShip.setPosition({ mWidth / 2, mHeight / 2 });
            mShip.setAngularPos(0);

            /*Message de fin de jeu*/
            if (mCollision.collisionAsteroide())
            {
                //àfaire
            }

            mCollision.CollisionOccured(false);
        }

    }

    // 2) S'il n'y a pas de collision
    else
    {
        // 2.1) Calculer l'accélération linéaire pour la touche "Up"
        if (keyboard.isKeyPressed(ezapp::Keyboard::Key::Up))
            acceleration.setFromPolar(m, mShip.angularPos() + (3.0f * 3.141592654f) / 2.0f);

        // 2.2) Calculer l'accélération linéaire pour la touche "Down"
        if (keyboard.isKeyPressed(ezapp::Keyboard::Key::Down))
            acceleration.setFromPolar(-m, mShip.angularPos() + (3.0f * 3.141592654f) / 2.0f);

        // 2.3) Calculer l'accélération angulaire pour la touche "Right"
        if (keyboard.isKeyPressed(ezapp::Keyboard::Key::Right))
            angularAcc = (m / c);

        // 2.4) Calculer l'accélération angulaire pour la touche "Left"
        if (keyboard.isKeyPressed(ezapp::Keyboard::Key::Left))
            angularAcc = (-m / c);

        // 2.5) Mettre à jour l'accélération linéaire du vaisseau spatial.
        mShip.setAcceleration(acceleration);

        // 2.6) Mettre à jour la position et la vitesse linéaire.
        mShip.processTime(timer.secondSinceLastTic());

        // 2.7) Mettre à jour l'accélération angulaire du vaisseau spatial.
        mShip.setAngularAcc(angularAcc);

        // 2.8) Mettre à jour la position et la vitesse angulaire.
        mShip.angularProcessTime(timer.secondSinceLastTic());

        // 2.9) Accumuler la distance parcourue.
        mShip.distanceMade(timer.secondSinceLastTic());

        // 2.10) Gérer les collisions des astéroïdes et l'espace du jeu
        // ainsi que la collision entre le vaisseau spatial et
        // un astéroïde.
        for (auto& Asteroid : mAsteroid) {
            mCollision.collisionSpaceshipAsteroid(mShip, Asteroid);

            if(mShip.missileShot())
                mCollision.collisionMissileAsteroid(mShip, Asteroid);
        }
        // 2.11 Gérer la collision entre le vaisseau spatial et les bordures
        // du jeu.
        mCollision.collisionSpaceshipWall(mShip);

        // 3.1) Missile
        mShip.manageMissile(keyboard.isKeyPressed(ezapp::Keyboard::Key::Space), timer.secondSinceLastTic());

        if (mShip.missileShot())
            mCollision.collisionMissileWall(mShip);
    }

    // Retourner false si l'utilisateur a appuyé sur la touche ESC
    // afin d'arrêter le jeu.

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
    screen.setBrush(mBackgroundColor.red(), mBackgroundColor.green(),
        mBackgroundColor.blue(), mBackgroundColor.alpha());
    screen.clear();
    // S'il y a lieu, tracer les éléments/corps avant les astéroïdes
    // Tracer les astéroîdes sur le canvas (écran) de EzApp
    for (auto& Asteroid : mAsteroid) {
        Asteroid.draw(screen);
    }
    for (auto& EnemyShip : mEnemyShip) {
        EnemyShip.draw(screen);
    }
    // S'il y a lieu, tracer les éléments/corps après les astéroïdes

    // Afficher un message expliquant cette étape (à enlever dans la version
    // finale du jeu)
    Polygon message;
    std::string msg = "Étape 1: Déplacement des astéroïdes";
    message.setColors(Color(1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f));
    message.drawText(screen, msg, 20.0f, 35.0f, 0.0f, 0.7f);


    // Tracer le vaisseau spatial
    mShip.draw(screen);

    // Tracer le missile
    mShip.drawMissile(screen);

    // Afficher ses statistiques
    mShip.drawDistanceMade(screen);
    mShip.drawBestDistance(screen);
    mShip.drawNbMissile(screen);
}
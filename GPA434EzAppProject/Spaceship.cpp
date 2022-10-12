/*  Spaceship.cpp
 *  Cette classe g�re une forme polygonale repr�sentante un viasseau spatial. Voici les �l�ments
 *  g�r�s par elle:
 *    - Sa forme polygone qui est particuli�re;
 *    - Sa vitesse (lin�aire et angulaire);
 *    - Sa position (lin�aire et angulaire);
 *    - Son acc�l�ration (lin�aire et angulaire);
 *    - Son acc�l�ration (lin�aire et angulaire);
 *    - Sa distance parcourue;
 *    - Sa plus grande distance parcourue depuis le d�but du jeu;
 *    - Son dessin � l'�cran par le biais de la classe Polygon.
 *
 *  ------------------------------------------------------------------------------------------
 *  GPA434 Laboratoire #1
 *  Cette classe est d�j� r�alis�e en partie et les �tudiants doit la compl�ter.
 *  ------------------------------------------------------------------------------------------
 *  Techniques � �tudier
 *  ------------------------------------------------------------------------------------------
 *    - Comment construire la forme polygonale repr�sentant le vaisseau spatial;
 *    - Donner � un vaisseau spatial un comportement propre.
 *  ------------------------------------------------------------------------------------------
 *
 *  Commentaires et modification par: T. Wong
 *  01-2021
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de donn�es: PascalCase
 *    Variables, fonctions: camelCase
 */
#include "Spaceship.h"

 // Constructeur avec param�tres
Spaceship::Spaceship(float origineX, float origineY)
	: mPosition(origineX, origineY),
	mVelocity(),
	mAcceleration(),
	mAngularPos{},
	mAngularVel{},
	mAngularAcc{},
	mDistanceMade{},
	mBestDistance{},
	mShape(),
	mShapeMissile(),
	mMissile(-1.0f, -1.0f),
	vitesseMissile(-1, -1)
{
	// Le vaisseau spatial aura la couleur noire, des traits blancs d'�paisseur de 1. Le point au centre
	// du vaisseau est � (0, 0).
	mShape.buildSpaceship(Color(1.0f, 1.0f, 0.0f, 1.0f), Color(0.0f, 0.0f, 0.0f, 1.0f), 0.0f, 0.0f);
	mShapeMissile.buildMissile(Color(0.6f, 1.0f, 0.0f, 1.0f), Color(0.0f, 0.0f, 0.0f, 1.0f), 0.0f, 0.0f);
}

// Destructeur
Spaceship::~Spaceship()
{
	// do nothing
}

// --------------------------------------------------------------------------------------
// Accesseur(s) et mutateur(s) (fonctions membres)
// --------------------------------------------------------------------------------------
Vect2d Spaceship::position() const
{
	// Retourner la position lin�aire
	return mPosition;
}

Vect2d Spaceship::velocity() const
{
	// Retourner la vitesse lin�aire
	return mVelocity;
}

Vect2d Spaceship::acceleration() const
{
	// Retourner l'acc�l�ration lin�aire
	return mAcceleration;
}

float Spaceship::angularPos() const
{
	// Retourner la position angulaire
	return mAngularPos;
}

float Spaceship::angularVel() const
{
	// Retourner la vitesse angulaire
	return mAngularVel;
}

float Spaceship::angularAcc() const
{
	// Retourner l'acc�l�ration angulaire
	return mAngularAcc;
}

float Spaceship::distanceMade() const
{
	return mDistanceMade;
}

void Spaceship::setPosition(Vect2d const& position)
{
	// Assigner la position lin�aire
	mPosition = position;
}

void Spaceship::setVelocity(Vect2d const& velocity)
{
	// Assigner la vitesse lin�aire
	mVelocity = velocity;
}

void Spaceship::setAcceleration(Vect2d const& acceleration)
{
	// Assigner l'acc�l�ration lin�aire
	mAcceleration = acceleration;
}



void Spaceship::setAngularPos(float const& angularPos)
{
	// Assigner la position angulaire
	mAngularPos = angularPos;
}

void Spaceship::setAngularVel(float const& angularVel)
{
	// Assigner la vitesse angulaire
	mAngularVel = angularVel;
}

void Spaceship::setAngularAcc(float const& angularAcc)
{
	// Assigner l'acc�l�ration angulaire
	mAngularAcc = angularAcc;
}

void Spaceship::resetAngularAcc()
{
	// RAZ: Assigner 0.0f � l'acc�l�ration angulaire
	mAngularAcc = 0.0f;
}

void Spaceship::resetVerticalPositionDown(float const& height)
{
	mPosition.setY(height);
}

void Spaceship::resetHorizontalPositionDown(float const& width)
{
	mPosition.setX(width);
}


void Spaceship::resetDistanceMade()
{
	// RAZ: Assigner 0.0f � la distance parcourue
	mDistanceMade = 0.0f;
}

// RAZ les attributs du vaisseau spatial (apr�s une collision)
void Spaceship::resetSpaceship(float const& width, float const& height)
{
	// Repositionner le vaisseau au milieu de l'espace du jeu
	setPosition(Vect2d(width / 2, height / 2));
	// RAZ position angulaire
	setAngularPos(0.0f);
	// RAZ la distance parcourue
	resetDistanceMade();
	// Remettre la couleur de remplissage � noir
	mShape.setFill(Color(1.0f, 1.0f, 0.0f, 1.0f));
}

// --------------------------------------------------------------------------------------
// Mise � jour de la position et la vitesse lin�aire du viasseau spatial
// Cette fonction membre est ex�cut�e p�riodiquement par l'Engine du jeu.
//
// Note 1: d = vt + 1/2at^2 et v = at
// Note 2: On re�oit le temps �coul� depuis la derni�re mise � jour. La nouvelle
//         position et la nouvelle vitesse sont obtenue en s'additionnant avec
//         leur valeur pr�c�dente.
// --------------------------------------------------------------------------------------
void Spaceship::processTime(float const& elapsedTime) // Update position vector 
{
	// 1) Calculer la nouvelle position lin�aire
	//    Profitez du fait que Vect2d poss�de les op�rateurs d'addition et de multiplication
	//    pour simplifier le codage.
	mPosition += mVelocity * elapsedTime + 0.5 * (mAcceleration) * (elapsedTime * elapsedTime);

	// 2) Calculer la nouvelle vitesse
	mVelocity += mAcceleration * elapsedTime;

	// 3) RAZ l'acc�l�ration lin�aire car l�acc�l�ration
	//    est recalcul�e � chaque pas de temps par GameEngine
	mAcceleration = 0;
}


// --------------------------------------------------------------------------------------
// Mise � jour de la position et la vitesse angulaire du viasseau spatial
// Cette fonction membre est ex�cut�e p�riodiquement par l'Engine du jeu.
//
// Note 1: d = vt + 1/2at^2 et v = at
// Note 2: On re�oit le temps �coul� depuis la derni�re mise � jour. La nouvelle
//         position et la nouvelle vitesse sont obtenue en s'additionnant avec
//         leur valeur pr�c�dente.
// --------------------------------------------------------------------------------------
void Spaceship::angularProcessTime(float const& elapsedTime)
{
	// 1) Calculer la nouvelle position angulaire
	//    Profitez du fait que Vect2d poss�de les op�rateurs d'addition et de multiplication
	//    pour simplifier le codage.
	mAngularPos += mAngularVel * elapsedTime + 0.5 * mAngularVel * (elapsedTime * elapsedTime);

	// 2) Calculer la nouvelle vitesse angulaire
	mAngularVel += mAngularAcc * elapsedTime;

	// 3) RAZ l'acc�l�ration lin�aire car l�acc�l�ration
	//    est recalcul�e � chaque pas de temps par GameEngine
	mAngularAcc = 0;
}

// --------------------------------------------------------------------------------------
// Dessiner la forme polygonale dont le centre est au point mPosition.
// Cette fonction membre est normalement ex�cut�e apr�s la MAJ de la position.
// --------------------------------------------------------------------------------------
void Spaceship::draw(ezapp::Screen& screen) const
{
	// Utiliser l'objet mShape pour dessiner la forme polygonale � partir
	// de sa position lin�aire et angulaire.

	mShape.draw(screen, mPosition.x(), mPosition.y(), mAngularPos);
}

// --------------------------------------------------------------------------------------
// Cumuler la distance parcourue par le vaisseau spatial.
//
// Note 1: d = vt
// Note 2: La vitesse lin�aire v est exprim�e par rapport au plan cart�sien X, Y et il
//         faut prendre sa norme pour calculer la distance parcourue.
// --------------------------------------------------------------------------------------
void Spaceship::distanceMade(float const& elapsedTime)
{
	// 1) Cumuler la distance parcourue seulement si la norme de
	//    vitesse est sup�rieure � une certainement valeur. C�est
	//    � dire que le vaisseau est effectivement en mouvement.
	if (mVelocity.norm() >= 5.0f)
	{
		// 2) Cumuler la distance parcourue par le vaisseau spatial.
		mDistanceMade += mVelocity.norm() * elapsedTime;
	}
}

// --------------------------------------------------------------------------------------
// Afficher la distance parcourue dans l'espace du jeu.
// --------------------------------------------------------------------------------------
void Spaceship::drawDistanceMade(ezapp::Screen& screen) const
{
	Polygon distance;
	// 1) Former la cha�ne de caract�re contenant la distance parcourue.
	std::string msg = "Distance Parcouru: " + std::to_string(mDistanceMade);

	// 2) Donner les couleurs.
	distance.setColors(Color(1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f));

	// 3) Utiliser la fonction membre de l'objet Polygon pour dessiner la cha�ne de caract�re
	//    dans l'espace du jeu.
	distance.drawText(screen, msg, 20.0f, 55.0f, 0.0f, 0.7f);

}

/*�crire l'�cran de fin de partie*/
void Spaceship::drawGameOverScreen(ezapp::Screen& screen) const
{
	Polygon GameOverString;
	// 1) Former la cha�ne de caract�re contenant la distance parcourue.
	std::string msg = "Ah, vous ne vous �tes m�me pas rendu � " + std::to_string(floor(mDistanceMade))
		+ "\nCliquez sur espace pour recommencer le jeu.";

	// 2) Donner les couleurs.
	GameOverString.setColors(Color(1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f));

	// 3) Utiliser la fonction membre de l'objet Polygon pour dessiner la cha�ne de caract�re
	//    dans l'espace du jeu.
	GameOverString.drawText(screen, msg, 200.0f, 200.0f, 0.0f, 0.7f);
}

// --------------------------------------------------------------------------------------
// Afficher la plus grande distance parcourue dans l'espace du jeu.
// --------------------------------------------------------------------------------------
void Spaceship::drawBestDistance(ezapp::Screen& screen) const
{
	Polygon distance;
	// 1) Former la cha�ne de caract�re contenant la plus grande distance parcourue.
	std::string msg = "Meilleur distance Parcouru: " + std::to_string(mBestDistance);

	// 2) Donner les couleurs.
	distance.setColors(Color(1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f));

	// 3) Utiliser la fonction membre de l'objet Polygon pour dessiner la cha�ne de caract�re
	//    dans l'espace du jeu.
	distance.drawText(screen, msg, 20.0f, 75.0f, 0.0f, 0.7f);

}

// --------------------------------------------------------------------------------------
// Modifier les attributs du vaisseau spatial apr�s une collision avec un as�tro�de
//
// Note: Cette fonction membre NE D�TECTE PAS une collision. Elle sert plu�t � g�rer
//       le comportement du vaisseau spatial � la suite d'une collision avec un
//       ast�ro�de.
// --------------------------------------------------------------------------------------
void Spaceship::collison()
{
	// 1) Changer la couleur du vaisseau spatial pour indiquer une collision a eu lieu
	mShape.setFill(Color(1.0f, 0.0f, 0.0f));
	// 2) RAZ sa vitesse lin�aire
	mVelocity = 0;

	// 3) RAZ sa vitesse angulaire
	mAngularVel = 0;

	// 4) Mettre � jour la plus grande distance parcourue
	mBestDistance = mDistanceMade;
}

bool Spaceship::missileShot() const
{
	return mMissile.missileShot();		// Retourne l��tat du missile (tir�, non tir�)
}

void Spaceship::resetMissileShot(bool const& missileShot)
{
	// 1) R�gle l'�tat du missile
	mMissile.setMissileShot(missileShot);
	// 2) RAZ la position du missile
	mMissile.setPosition(Vect2d(-10.0f, -10.0f));
}

void Spaceship::manageMissile(bool const& spaceBarPressed, float const& elapsedTime)
{
	const float missileVel = 150.0f; // Module de la vitesse du missile
	//Vect2d norm;
	//Vect2d angle;

	// 1) Si la touche SPACEBAR est appuy�e et que le missile est disponible � tirer...
	if (spaceBarPressed == true and mMissile.missileShot() == false)
	{
		// 1.1) R�gle l'�tat du missile � � tir� �
		mMissile.setMissileShot(true);

		// 1.2) R�gle la position lin�aire du missile (m�me que celle du vaisseau spatial)
		mMissile.setPosition(mPosition);  //mPosition du Spaceship?

		// 1.3) R�gle la position angulaire du missile (m�me que celle du vaisseau spatial)
		mMissile.setAngularPos(mAngularPos); // AngPos du Spaceship?
		vitesseMissile.setFromPolar(missileVel, mMissile.angularPos() - (90.0f * 3.141592654f)/180.0f);

		// 1.4) Calculer la vitesse du missile et l'assigner au missile
		mMissile.setVelocity(vitesseMissile);
	}
	// 2) Si le missile a �t� tir�
	if (mMissile.missileShot() == true)
	{
		// Alors mettre � jour la position du missile
		mMissile.processTime(elapsedTime);
	}
}

void Spaceship::drawMissile(ezapp::Screen& screen) const
{
	mShapeMissile.draw(screen, mMissile.position().x(), mMissile.position().y(), mMissile.angularPos());
	// Dessiner le missile
}




void Spaceship::drawNbMissile(ezapp::Screen& screen,
	float const& width) const
{
	/************************************************/
	// Dessiner une indication visuelle pour signifier
	// au joueur qu�il peut tirer � nouveau
}

Vect2d Spaceship::positionMissile() const
{
	// Retourner la position lin�aire du missile
	return mMissile.position();
}

void Spaceship::collisionMissileWall() 
{
	mMissile.collison();
}
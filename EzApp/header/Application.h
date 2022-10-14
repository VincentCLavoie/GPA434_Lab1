#pragma once


#include <memory>
#include <string>
#include <functional>


namespace ezapp {

    class Screen;
    class Timer;
    class Keyboard;
        
    // EzApp est écrit à partir de SFML
    //
    // La classe Application est au coeur de la librairie EzApp.
    //
    // Il suffit d'en créer une instance et d'appeler simplement la fonction run.
    // La fonction run requiert deux fonctions lui pemettant de faire :
    //  1. les calculs à chaque pas (considérant les entrées au clavier et le temps écoulé)
    //  2. l'affichage pour chaque pas (l'affichage à l'écran)
    class Application
    {
    public:
        class Parameters;
        using UpdateModelFunction = bool(Keyboard const &, Timer const &);
        using UpdateViewFunction = void(Screen &);

        Application();
        Application(Parameters const & parameters);
        ~Application();

        Parameters const & parameters() const;

        void run(std::function<UpdateModelFunction> updateModel, std::function<UpdateViewFunction> updateView);
        
        template <typename Model, typename View>
        void run(Model & model, bool(Model::*updateModel)(Keyboard const &, Timer const &), View & view, void(View::*updateView)(Screen &));
        template <typename ModelView>
        void run(ModelView& modelView, bool(ModelView::* updateModel)(Keyboard const&, Timer const&), void(ModelView::* updateView)(Screen&));

    private:
        class Impl;
        std::unique_ptr<Impl> mImpl;
        void * w();

        friend class Screen;
    };


    // Paramètres d'une application EzApp
    class Application::Parameters
    {
    public:
        Parameters(size_t width = 800, size_t height = 600, std::string const& title = "EzApp", std::string const& iconFileName = "", std::list<std::string> const& fontToPreload = {});

        bool isValid() const;                                               //!< Retourne vrai si les paramètres sont valides (principalement si la taille est suffisante)

        void setTitle(std::string const & title);                           //!< Détermine le titre de la fenêtre
        void setIconFileName(std::string const & iconFileName);             //!< Détermine le nom du fichier à charger représentant l'icône
        void setWindowSize(size_t width, size_t height);                    //!< Détermine la taille de la fenêtre
        void setFontToPreload(std::list<std::string> const & fontToPreload);//!< Détermine la liste des fichiers de police de caractères à charger
        
        std::string title() const;                                          //!< return le titre de la fenêtre
        std::string iconFileName() const;                                   //!< Retourne le nom du fichier représentant l'icône
        size_t width() const;                                               //!< Retourne la largeur de la fenêtre
        size_t height() const;                                              //!< Retourne la hauteur de la fenêtre
        std::list<std::string> const & fontToPreload() const;               //!< Retourne la liste des fichiers de police de caractères

        static size_t const minSize();                                      //!< Retourne la taille la plus petite permise de la fenêtre

    private:
        std::string mTitle;
        std::string mIconFileName;
        size_t mWidth;
        size_t mHeight;
        std::list<std::string> mFontToPreload;

        static size_t const sMinSize;
    };





    template <typename Model, typename View>
    inline void Application::run(Model & model, bool(Model::* updateModel)(Keyboard const &, Timer const &), View & view, void(View::* updateView)(Screen &)) {
        run(std::bind(updateModel, &model, std::placeholders::_1, std::placeholders::_2), std::bind(updateView, &view, std::placeholders::_1));
    }

    template <typename ModelView>
    inline void Application::run(ModelView& modelView, bool(ModelView::* updateModel)(Keyboard const&, Timer const&), void(ModelView::* updateView)(Screen&)) {
        run(modelView, updateModel, modelView, updateView);
    }
}

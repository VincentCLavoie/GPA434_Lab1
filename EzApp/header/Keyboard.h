#pragma once


#include <cstdint>


namespace ezapp {

    //! \brief Permet de connaître l'état du clavier.
    class Keyboard
    {
    public:
        // Énumération des touches claviers pouvant être détecté
        enum class Key : int32_t {
            Unknown = -1,
            A = 0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
            Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
            Escape,
            LControl, LShift, LAlt, LSystem,
            RControl, RShift, RAlt, RSystem,
            Menu,
            LBracket, RBracket,
            Semicolon, Comma, Period,
            Quote, Slash, Backslash, Tilde, Equal, Hyphen,
            Space, Enter, Backspace, Tab,
            PageUp, PageDown, End, Home, Insert, Delete,
            Add, Subtract, Multiply, Divide,
            Left, Right, Up, Down,
            Numpad0, Numpad1, Numpad2, Numpad3, Numpad4, Numpad5, Numpad6, Numpad7, Numpad8, Numpad9, 
            F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15,
            Pause,
            __count__
        };

        bool isKeyPressed(Key key) const; //!< Retourne vrai si la touche demandée est appuyée sinon retourne faux.

    private:
        Keyboard() = default;
        Keyboard(Keyboard const &) = delete;
        Keyboard(Keyboard &&) = delete;
        Keyboard& operator=(Keyboard const &) = delete;
        Keyboard& operator=(Keyboard &&) = delete;
        ~Keyboard() = default;

        friend class Application;
    };

}


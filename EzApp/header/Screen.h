#pragma once


#include <memory>
#include <vector>
#include <string>


namespace ezapp {
    
    class Application;

    //! \brief Permet de dessiner à l'écran.
    class Screen
    {
    public:
        // Détermine la couleur et l'épaisseur du contour
        void noPen();
        void setPen(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f, float width = 1.0f);
        // Détermine la couleur du remplissage
        void noBrush();
        void setBrush(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f);

        // Dessine complètement l'écran de la couleur de remplissage
        void clear();
        
        // Pour dessiner un polygone :
        // 1. setPen ou noPen       défini la couleur et l'épaisseur du contour
        // 2. setBrush ou noBrush   défini la couleur du remplissage
        // 3. setPolygonVertices    détermine les sommets du polygone à dessiner
        // 4. drawPolygon           dessine le polygone (applique les transformations affines données)
        void setPolygonVertices(size_t verticesCount, float const * verticesRawBuffer);
        template <typename t>
        void setPolygonVertices(std::vector<t> const & vertices);
        void drawPolygon(float x, float y, float rotation = 0.0f, float scale = 1.0f);

        // Pour dessiner du texte :
        // 1. setPen ou noPen       défini la couleur et l'épaisseur du contour
        // 2. setBrush ou noBrush   défini la couleur du remplissage
        // 3. setTextFont           détermine la police de caractères à utiliser (n'est pas à redéfinir si on utilise la même police)
        // 4. setTextSizes          détermine les tailles reliées à la police de caractères
        // 5. setTextStyle          détermine les styles de la police : gras - italique - souligné - barré
        // 6. drawText              dessine le texte (applique les transformations affines données)
        bool setTextFont(std::string const & fontName);
        void setTextSizes(size_t characterSize = 30, float letterSpacingRatio = 1.0f, float lineSpacingRatio = 1.0f);
        void setTextStyle(bool bold = false, bool italic = false, bool underline = false, bool strikeThrough = false); // to do : incomplete - not working
        void drawText(std::string const & text, float x, float y, float rotation = 0.0f, float scale = 1.0f);

        std::string currentFont() const;

    private:
        Screen(Application & app);
        Screen(Screen const &) = delete;
        Screen(Screen &&) = delete;
        Screen& operator=(Screen const &) = delete;
        Screen& operator=(Screen &&) = delete;
        ~Screen();

        class Impl;
        std::unique_ptr<Impl> mImpl;

        friend class Application;
    };





    template <typename t>
    void Screen::setPolygonVertices(std::vector<t> const & vertices)
    {
        static_assert(sizeof(t) == 2 * sizeof(float), "Invalid template argument in Screen::setPolygonVertices : t must be a structure of two float.");
        setPolygonVertices(vertices.size(), reinterpret_cast<float const *>(vertices.data()));
    }

    //template <typename t>
    //void Screen::drawPolygonByGetters(float x, float y, float rotation, std::vector<t> const & vertices) {
    //    //static_assert : possède les fonctions x() et y()
    //
    //    std::vector<std::pair<float, float>> v(vertices.size());
    //    auto vin{ vertices.begin() };
    //    auto vout{ v.begin() };
    //    while (vin != vertices.end()) {
    //        vout->first = vin->x();
    //        vout->second = vin->y();
    //        ++vin;
    //        ++vout;
    //    }
    //    drawPolygon(x, y, rotation, v.size(), reinterpret_cast<float const *>(v.data()));
    //}

}


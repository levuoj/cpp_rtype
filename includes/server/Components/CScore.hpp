//
// Created by Oraekia on 10/01/18.
//

#ifndef CPP_RTYPE_CSCORE_HPP
#define CPP_RTYPE_CSCORE_HPP


#include <server/AComponent.hpp>

namespace FF {
    class CScore : public AComponent {
    private:
        int _score;
    public:
        CScore();
        virtual ~CScore() = default;

        void increase(int points) { _score += points; }
        void setScore(int score) { _score = score; }
        int getScore() const { return (_score); }

        void init() final;
    };
}

#endif //CPP_RTYPE_CSCORE_HPP

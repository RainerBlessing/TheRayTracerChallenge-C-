//
// Created by rainer on 29.12.19.
//

#ifndef RAY_TRACER_CHALLENGE_OBJECT_H
#define RAY_TRACER_CHALLENGE_OBJECT_H


class Object {
public:
    bool operator == (Object o) const;
    Object();
private:
    int id;
    const int getRandomNumber() const;
};


#endif //RAY_TRACER_CHALLENGE_OBJECT_H

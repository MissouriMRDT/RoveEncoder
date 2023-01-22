#ifndef ROVEENCODER_H
#define ROVEENCODER_H

class RoveEncoder {

protected:

    bool m_inverted = false;
    float m_offsetDegrees = 0;

public:

    void configInvert(bool invert);
    void configOffset(float offsetDegrees);

    float readRadians();
    virtual float readDegrees() = 0;
    
};

#endif
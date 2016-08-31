#include "DS18B20.h"

DS18B20::DS18B20(uint8_t pin)
{
    ds = new OneWire(pin);
    isDetected = false;
}

DS18B20::~DS18B20()
{
    delete ds;
}

uint8_t DS18B20::search()
{
    if(!ds->search(address))
    {
        isDetected=false;
        ds->reset_search();
        return 1;
    }
    if(OneWire::crc8(address,7) != address[7])
    {
        isDetected=false;
        return 2;
    }
    if(address[0]!=DS18B20_address)
    {
        isDetected=false;
        return 3;
    }

    isDetected=true;
    return 0;
}

boolean DS18B20::getTemp(double* temp)
{
    if(!this->detected())
        return false;

    ds->reset();
    ds->select(address);
    ds->write(0x44, 1);
    delay(800);

    ds->reset();
    ds->select(address);
    ds->write(0XBE);

    for(byte i=0; i<9; i++)
        data[i]=ds->read();

    *temp = ((data[1] << 8) | data[0]) * 0.0625;
    return true;
}

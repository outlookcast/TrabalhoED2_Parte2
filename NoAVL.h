class NoAVL
{
public:
    NoAVL() {};
    ~NoAVL() {};
    void setEsq(NoAVL *p)
    {
        esq = p;
    }

    void setDir(NoAVL *p)
    {
        dir = p;
    }

    void setInfo(int c)
    {
        info = c;
    }

    NoAVL * getEsq()
    {
        return esq;
    }

    NoAVL * getDir()
    {
        return dir;
    }

    int getInfo()
    {
        return info;
    }
    int getAltura()
    {

        return altura;
    }
    void setAltura(int x)
    {

        altura = x;
    }

    int getBalanciamento()
    {

        return fatorBanciamento;
    }

    void setBalanciamento(int x)
    {

        fatorBanciamento = x;
    }

private:
    int info;
    NoAVL * esq;
    NoAVL * dir;
    int altura;
    int fatorBanciamento;
};

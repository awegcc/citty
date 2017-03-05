#ifndef CITTYCONFIG_H
#define CITTYCONFIG_H

#include <wx/config.h>


class cittyConfig : public wxConfig
{
    public:
        cittyConfig();
        virtual ~cittyConfig();

    protected:

    private:
};

#endif // CITTYCONFIG_H

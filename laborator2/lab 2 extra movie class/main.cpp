#include <iostream>
#include "Movie.h"
#include "global.h"
#include "MovieSeries.h"

using namespace std;

int main()
{
    Movie ep5;
    ep5.set_name("Star Wars: Episode V - The Empire Strikes Back");
    ep5.set_score(8.7);
    ep5.set_year(1980);
    ep5.set_length(124);

    Movie ep4;
    ep4.set_name("Star Wars: Episode IV - A New Hope");
    ep4.set_score(8.6);
    ep4.set_year(1977);
    ep4.set_length(121);

    Movie ep6;
    ep6.set_name("Star Wars: Episode VI - Return of the Jedi");
    ep6.set_score(8.3);
    ep6.set_year(1983);
    ep6.set_length(131);

    Movie ep7;
    ep7.set_name("Star Wars: Episode VI - Alabalaportocala");
    ep7.set_score(8.1);
    ep7.set_year(1960);
    ep7.set_length(140);

    Movie ep3;
    ep3.set_name("Star Wars: Episode VI - Cinemiafuratbanana");
    ep3.set_score(6.3);
    ep3.set_year(2001);
    ep3.set_length(111);

    MovieSeries starwars;
    starwars.init();
    starwars.add(&ep4);
    starwars.add(&ep6);
    starwars.add(&ep7);
    starwars.add(&ep3);
    starwars.add(&ep5);
    starwars.sort();
    starwars.print();

	return 0;
}
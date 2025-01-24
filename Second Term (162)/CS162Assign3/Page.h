#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <cstring>

using namespace std;

/**
 * @brief The Page class represents a web page
 */
class Page
{
public:

    /**
     * @brief Page Constructs a page with an empty url, no links, and all values set to 0
     */
    Page();

    /**
     * @brief Page Constructs a page with a given url and sets all values to 0 and nullptr
     * @param urlValue Takes in a string and replaces the url with it
     */
    Page(string urlValue);

    /**
     * @brief getURL Accesses the url in Page
     * @return the url found
     */
    string getURL() const;

    /**
     * @brief getNumLinks Accesses the amount of links used inside Page object
     * @return the amount of links used
     */
    int getNumLinks() const;

    /**
     * @brief getRandomLink Creates a random value based on the amount of pages in array and uses value to choose a page
     * @return a random page in the array
     */
    Page* getRandomLink() const;

    /**
     * @brief addLink Connects the given page to the other pages
     * @param other Page used to add to the links array
     */
    void addLink(Page* other);

    /**
     * @brief visit Adds one to the visit value everytime function is used
     */
    void visit();

    /**
     * @brief getNumVisits Accesses the amount of visits used inside a Page object
     * @return the number of visits for the page
     */
    int getNumVisits() const;


private:
    string url;
    int visits;
    Page* links[3];
    int usedLinks;
};


#endif // PAGE_H

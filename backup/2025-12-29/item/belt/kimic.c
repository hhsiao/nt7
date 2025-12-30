// cruise-ob.c

#include "/clone/misc/belt_ob.h"

string long() 
{
        string msg; 
        
        msg = query("long"); 
        msg += "這是東邪西毒(kimic)的勳章掛帶。
";
        
        //return sort_string(msg, 64, 0); 
        return msg;
}

void owner_is_killed() { destruct(this_object()); } 
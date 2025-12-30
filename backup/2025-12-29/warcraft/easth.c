// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m東方天八[2;37;0m[2;37;0m", ({"easthh"}));        
        set("gender", "女性");                
        set("long", "$HIW$東方天八[2;37;0m
它是東方八的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "easth");
        set("owner_name", "東方八");
        set_temp("owner", "easth");
        set_temp("owner_name", "東方八");
        ::setup();
}

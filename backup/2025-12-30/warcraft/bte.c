// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("加肥貓[2;37;0m[2;37;0m", ({"omo"}));        
        set("gender", "女性");                
        set("long", "一直特別肥特別大的肥貓，但是卻行動敏捷。[2;37;0m
它是周丹五的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "bte");
        set("owner_name", "周丹五");
        set_temp("owner", "bte");
        set_temp("owner_name", "周丹五");
        ::setup();
}

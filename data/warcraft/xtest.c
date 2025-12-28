// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("顏色[2;37;0m[2;37;0m", ({"idid"}));        
        set("gender", "男性");                
        set("long", "顏色[2;37;0m
它是回車的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xtest");
        set("owner_name", "回車");
        set_temp("owner", "xtest");
        set_temp("owner_name", "回車");
        ::setup();
}

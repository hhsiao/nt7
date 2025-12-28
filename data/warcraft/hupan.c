// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("電眼飛狐[2;37;0m[2;37;0m", ({"feihu"}));        
        set("gender", "男性");                
        set("long", "電眼飛狐[2;37;0m
它是張湖畔的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hupan");
        set("owner_name", "張湖畔");
        set_temp("owner", "hupan");
        set_temp("owner_name", "張湖畔");
        ::setup();
}

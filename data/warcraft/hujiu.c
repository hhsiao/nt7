// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m九尾狐[2;37;0m[2;37;0m", ({"jiuweihu"}));        
        set("gender", "男性");                
        set("long", "妖嬈的九條尾巴狐狸[2;37;0m
它是胡九的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hujiu");
        set("owner_name", "胡九");
        set_temp("owner", "hujiu");
        set_temp("owner_name", "胡九");
        ::setup();
}

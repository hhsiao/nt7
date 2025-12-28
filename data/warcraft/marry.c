// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("繪色千佳[2;37;0m[2;37;0m", ({"cici"}));        
        set("gender", "女性");                
        set("long", "繪色千佳是Erotica公司旗下AV女優[2;37;0m
它是嗶嗶啦啦的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "marry");
        set("owner_name", "嗶嗶啦啦");
        set_temp("owner", "marry");
        set_temp("owner_name", "嗶嗶啦啦");
        ::setup();
}

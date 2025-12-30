// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m烏雲[5m[1;37m蓋雪[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹神駒通體雪白，馬背黑色如雲，追風逐電、神駿非凡。[2;37;0m
它是秦瓊的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "qiong");
        set("owner_name", "秦瓊");
        set_temp("owner", "qiong");
        set_temp("owner_name", "秦瓊");
        ::setup();
}

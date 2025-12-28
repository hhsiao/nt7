// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m鈴木[5m[1;37m盜匪[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這是鈴木公司最新款街頭跑車，不時發出轟鳴聲，泡妞利器[2;37;0m
它是流川楓的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "balll");
        set("owner_name", "流川楓");
        set_temp("owner", "balll");
        set_temp("owner_name", "流川楓");
        ::setup();
}

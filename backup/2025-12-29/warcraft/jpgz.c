// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m血靈[2;37;0m[2;37;0m", ({"xueling"}));        
        set("gender", "女性");                
        set("long", "四大神獸之朱雀一族，後為極品公子所馴服。[2;37;0m
它是極品公子的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "jpgz");
        set("owner_name", "極品公子");
        set_temp("owner", "jpgz");
        set_temp("owner_name", "極品公子");
        ::setup();
}

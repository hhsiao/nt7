// This program is a part of NITAN MudLIB 
// redl 2013/8

#include <ansi.h>
inherit NPC;

void sp_attack();
void create()
{
        set_name(HIR "武痴" NOR, ({ "wu chi", "wu", "chi" }));
        set("long", NOR "這人練武練成瘋魔，曾是楊小邪最大的對手，據說怎麼打也打不死。\n" NOR);
        set("title", HIB "瘋子" NOR);
        set("attitude", "aggressive");
        set("str", 1);
        set("con", 1);
        set("dex", 1);
        set("int", 1);
        set("max_qi", 1);
        set("max_jing", 1);
        set("neili", 1);
        set("max_neili", 1);
        set("max_jingli", 1);
        set("jingli", 1);
        set("jiali", 1);
        set("level", 199);
        set("combat_exp", 30000000000);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                        (: sp_attack :),
                        (: sp_attack :),
                        (: sp_attack :),
                        (: exert_function, "powerup" :),
                        (: exert_function, "shield" :),
                        (: exert_function, "recover" :),
                        (: exert_function, "dispel" :),
        }));

                set("auto_perform", 1);

        set("death_msg", NOR "\n$N噗通一頭栽倒在地上，死了！\n\n躺著的$N突然鯉魚打挺跳起來，嘴裡“哈哈哈...” \n$N狂笑著往上一層塔逃竄而去。。。\n\n" NOR);
        set("flee_msg", NOR "\n$N突然搖手，嘴裡“哈哈哈...” \n$N狂笑著往上一層塔逃竄而去。。。\n\n" NOR);

        setup();
}

int do_setdrops(int i)
{
        //神器不可太低，那完全無意義，畢竟24小時才有一次闖塔，
        //而到300層也就15次mf神器的機會，湊齊一套很難
        if (i >= 150) {//150層+，傳說、神器
                i = i / 50 - 2;
                if (i > 2) i = 2;
        set("drops", ([
                "RA&LEGEND60" : 66, 
                                "FI&/clone/tessera/rune25"   : 9,
                                "FI&/clone/tessera/rune26"   : 6,
                                "FI&/clone/tessera/rune27"   : 2,
                "RA&MYTH60" : i, 
        ]));
        } 
        else {//150層-，史詩、傳說
        set("drops", ([
                "RA&EPIL60" : 21, 
                                "FI&/clone/medicine/tianxin"   : 27,
                                "FI&/clone/medicine/baola"   : 9,
                                "FI&/clone/medicine/baoming"   : 3,
                "RA&LEGEND60" : 2 + i / 30, 
        ]));
        }
        return 1;
}

int do_copyskill(object ob)
{
        int tlv;
        object me;

        mapping hp_status, skill_status, map_status, prepare_status;
        mapping my;
        string *sname;
        string *mname;
        string *pname;
        int i, temp;
        mapping tmp, my_tmp, apply;

        me = this_object();
        
        tmp = ob->query_entire_temp_dbase(); 
        apply = tmp["apply"]; 
        my_tmp = me->query_entire_temp_dbase(); 
        
        if (query("copied")) return 1;
        
        tlv = query("tlv", environment());
        set("tlv", tlv);
        do_setdrops(tlv);
        
        if (mapp(skill_status = me->query_skills()))
        {
                skill_status = me->query_skills();
                sname = keys(skill_status);

                temp = sizeof(skill_status);
                for (i = 0; i < temp; i++)
                        me->delete_skill(sname[i]);
        }

        if (mapp(skill_status = ob->query_skills()))
        {
                skill_status = ob->query_skills();
                sname = keys(skill_status);

                for (i = 0; i < sizeof(skill_status); i++)
                        me->set_skill(sname[i], skill_status[sname[i]]);
        }
        
        if (mapp(map_status = me->query_skill_map()))
        {
                mname = keys(map_status);

                temp = sizeof(map_status);
                for (i = 0; i < temp; i++)
                        me->map_skill(mname[i]);
        }

        if (mapp(map_status = ob->query_skill_map()))
        {
                mname = keys(map_status);

                for(i = 0; i < sizeof(map_status); i++)
                        me->map_skill(mname[i], map_status[mname[i]]);
        }

        if (mapp(prepare_status = me->query_skill_prepare()))
        {
                pname = keys(prepare_status);

                temp = sizeof(prepare_status);
                for(i = 0; i < temp; i++)
                        me->prepare_skill(pname[i]);
        }

        if (mapp(prepare_status = ob->query_skill_prepare()))
        {
                pname = keys(prepare_status);

                for(i = 0; i < sizeof(prepare_status); i++)
                        me->prepare_skill(pname[i], prepare_status[pname[i]]);
        }

        hp_status = ob->query_entire_dbase();
        my = me->query_entire_dbase();

        my["str"] = hp_status["str"];
        my["int"] = hp_status["int"];
        my["con"] = hp_status["con"];
        my["dex"] = hp_status["dex"];
        my["per"] = hp_status["per"];
        my["kar"] = hp_status["kar"];

        my["max_qi"]     = hp_status["max_qi"];
        my["eff_qi"]     = hp_status["eff_qi"];
        my["qi"]         = hp_status["qi"];
        my["max_jing"]   = hp_status["max_jing"];
        my["eff_jing"]   = hp_status["eff_jing"];
        my["jing"]       = hp_status["jing"];
        my["max_neili"]  = hp_status["max_neili"];
        my["max_jingli"]  = hp_status["max_jingli"];
        my["neili"]      = hp_status["neili"];
        my["jiali"]      = hp_status["jiali"];
        my["combat_exp"] = hp_status["combat_exp"];
        my["family"] = hp_status["family"];
        my["born_family"] = hp_status["born_family"];
        my["character"] = hp_status["character"];

        my_tmp["apply"] = apply;

                me->reset_action();
        
        set("copied", 1);
}

int delay_flee()
{
        message_vision(append_color(query("flee_msg"),CYN), this_object());
        destruct(this_object());
        return 1;
}

int do_checkfighting()
{
        object me, ob;
        me = this_object();
        if ( me->is_fighting() && objectp(ob=present("qiu tu", environment())) ) {
                call_out("do_checkfighting", 1);
                return 1;
        }
        remove_call_out("do_checkfighting");
        call_out("delay_flee", 9);
        return 1;
}

int ttype() 
{
        if (!environment() || !objectp(environment())) return 0;
        return environment()->tower_type();
}

void cz_fang(object me)
{
        int i;
        i = me->query_skill("parry", 1);
        i = i * 2 / 3;
        set_skill("parry", i);
        i = me->query_skill("dodge", 1);
        i = i * 2 / 3;
        set_skill("dodge", i);
        i = me->query_skill("force", 1);
        i = i * 2 / 3;
        set_skill("force", i);
        i = query("max_qi");
        i = i * 2 / 3;
        set("max_qi", i);
        set("eff_qi", i);
        set("qi", i);
        i = query("max_jing");
        i = i * 2 / 3;
        set("max_jing", i);
        set("eff_jing", i);
        set("jing", i);
}

void init()
{
        object me, ob;

        //::init();
        if (this_object()->is_fighting()) return;
                if (objectp(ob=present("qiu tu", environment()))) {
                        do_copyskill(ob);
                        if (ttype()==2) {
                                cz_fang(this_object());
                        }
                }
                //do_copyskill(find_player("redl"));

                me = this_player();
                if (playerp(me) && !query("env/invisible", me)) {
                                this_object()->stop_busy();
                        kill_ob(me);
                        set("enemy_player", me);
                                remove_call_out("do_checkfighting");
                                call_out("do_checkfighting", 0);
                }

}

void sp_attack()
{
        object *enemies, enemy;
        string msg;
        object weapon;
        int i, dmg;

        enemies = query_enemy();
        if( !enemies || sizeof(enemies) == 0 )
                return;
        enemy = enemies[random(sizeof(enemies))];
        if( !enemy->is_busy() && !random(4) ) {
                msg = HIK "\n$N往前疾衝，突然一個踉蹌摔倒在地上，卻恰好滑出去抱住了$n的雙腳。\n" NOR;
                message_vision(append_color(msg, HIK),this_object(),enemy);
                enemy->start_busy(4+random(3));
                return;
        }
        
        i = random(100);
        if (i < 1) {
                        msg = HIK "\n$N埋頭縮身，鑽進$n的胯下，翻身伸出中指衝準上方狠狠一戳。\n  「千年殺」...\n" NOR;
                        msg+= HIK "$n張大嘴劇烈顫抖，如被雷擊散了全身經脈，軟若無骨地重重倒下。\n" NOR;
                    message_vision(append_color(msg, HIK),this_object(),enemy);
                    enemy->receive_damage("qi", query("max_qi", enemy)*2, this_object());
                    enemy->receive_wound("qi", query("max_qi", enemy)*2, this_object());
                    COMBAT_D->report_status(enemy);
                    message_vision(append_color("\n", HIK),this_object(),enemy);
                    enemy->unconcious(); 
                    if( !enemy->is_busy() ) enemy->start_busy(2);
        }
        else if (i < 6) {
                        if( objectp(weapon=query_temp("weapon", enemy)) ) {
                                msg = HIK "\n$N一個轉身，貓腰轉進$n的腋下，用食指貼著$n的胳肢窩輕輕一撓。\n" NOR;
                                msg+= HIK "頓時$n手臂酥麻麻地，再也握不住手中的兵刃，“噹啷”一聲掉落在地上。\n" NOR;
                            message_vision(append_color(msg, HIK),this_object(),enemy);
                                weapon->move(environment());
                                if( !enemy->is_busy() ) enemy->start_busy(2);
                        }
        }
        else if (i < 56) {
                dmg = query("tlv") * 10000 + 100000;
            dmg = dmg + random(dmg);
            
                switch( random(2) ){
                    case 0: 
                            msg = HIK "\n$N揚手“啪啪啪……”給了自己幾個耳光，$n看得一愣，不防卻中了一記撩陰腳。\n" NOR;
                        message_vision(append_color(msg, HIK),this_object(),enemy);
                                break;
                        case 1: 
                                msg = HIK "\n$N輕輕地往上方一飄，閃開攻勢後一把摟住$n的脖子，狠狠地就咬了一口。\n" NOR;
                        message_vision(append_color(msg, HIK),this_object(),enemy);
                                break;
                }
                        
                        enemy->receive_damage("qi",dmg,this_object());
                        enemy->receive_wound("qi",dmg/2,this_object());
                        COMBAT_D->report_status(enemy);
                        if( !enemy->is_busy() ) enemy->start_busy(2);
        }
        
        return;
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

varargs void die(object killer)
{
        object ob;
        mapping drops;

        if(random(3) && //33% can call_die
         objectp(ob = previous_object(0)) &&
            sscanf(base_name(ob), "/kungfu/skill/%*s") ) {
                this_object()->full_self();
                return;
        }
        
        if(!objectp(killer)) {
                killer = query("enemy_player");
        }

                if( objectp(killer) && mapp(drops = query("drops")) ) {
                        EQUIPMENT_D->killer_reward(killer,this_object(),drops);
                }
                
                message_vision(append_color(query("death_msg"),CYN), this_object());
                destruct(this_object());
                return;
}

void unconcious()
{
        object ob;
        
        ob = query_last_damage_from();
        if (ob) {
                die(ob);
                return;
        }
        ob = query_temp("last_opponent", this_object());
        if (ob) {
                die(ob);
                return;
        }
        ob = query("enemy_player");
        if (ob) {
                die(ob);
                return;
        }
    die();
        return;
}



// This program is a part of NT MudLIB

#include <ansi.h>

// "str","角色力量值提高１點\t",500,

mapping max_ability = ([
        "str"   : 500,
        "int"   : 500,
        "con"   : 500,
        "dex"   : 500,
        "kar"   : 70,
        "max_qi"    : 10,
        "max_jing"  : 10,
        "max_neili" : 10,
        "max_jingli": 10,
        "qi_recover": 20,
        "jing_recover" : 20,
        "neili_recover": 20,
        "attack": 10,
        "dodge" : 10,
        "parry" : 10,
        "double_damage": 10,
        "avoid_poison" : 10,
        "avoid_busy": 10,
        "avoid_weak": 10,
        "reduce_damage": 10,
]);

// 基本能力
string *bas_ability = ({
        "str",
        "int",
        "con",
        "dex",
        "kar",
        "max_qi",
        "max_jing",
        "max_neili",
        "max_jingli",
        "qi_recover",
        "jing_recover",
        "neili_recover",
        "attack",
        "dodge",
        "parry",
        "double_damage",
        "avoid_poison",
        "avoid_busy",
        "avoid_weak",
        "reduce_damage",
});

string *bas_ability_info = ({
        "角色力量值提高１點\t","角色才智值提高１點\t","角色體質值提高１點\t",
        "角色身法值提高１點\t","角色運氣值提高１點\t","最大氣血值提高１％\t",
        "最大精氣值提高１％\t","最大內力值提高１％\t","最大精力值提高１％\t",
        "恢復氣血提高５０點\t","恢復精氣提高５０點\t","恢復內力提高５０點\t",
        "直接命中機會增１％\t","直接閃避機會增１％\t","直接招架機會增１％\t",
        "觸發暴擊機會增１％\t","免疫毒素機會增１％\t","免疫忙亂機會增１％\t",
        "免疫虛弱機會增１％\t","化解傷害比例增１％\t",
});

mapping bas_ability_pot = ([
        "attack":       2,
        "dodge":        2,
        "parry":        2,
        "double_damage":3,
        "avoid_poison": 3,
        "avoid_busy":   3,
        "avoid_weak":   3,
        "reduce_damage":3,
]);

mapping fam_ability_pot = ([
        //5
]);

mapping fam_ability_data = ([
        //5
]);

mapping fam_ability = ([
        "少林派": ({
                "dodgeup-shaolin-shenfa", "parryup-jingang-buhuaiti", "cd-jgbht-protect", "cd-yjj-buddha", "ap_power-ryb-shang",
                "da_power-ryb-shang", "ap_power-lhj-lunhui", "da_power-lhj-lunhui", "cd-lhj-lunhui",
        }),

        "武當派": ({
                "dodgeup-tiyunzong", "parryup-taiji-quan", "parryup-taiji-jian", "ap_power-tjq-tu", "da_power-tjq-tu", "cd-tjq-tu",
                "ap_power-tjq-zhen", "da_power-tjq-zhen", "ap_power-tjj-jian", "da_power-tjj-jian", "cd-tjj-jian",
        }),

        "峨嵋派": ({
                "dodgeup-zhutian-bu", "parryup-piaoxue-zhang", "ap_power-pxz-zhao", "parryup-huifeng-jian", "ap_power-hfj-jue", "da_power-hfj-jue", "cd-ljz-niepan"
        }),

        "華山派": ({
                "powerup-zxsg-ziqi", "dodgeup-feiyan-huixiang", "parryup-lonely-sword", "ap_power-dgjj-hun", "da_power-dgjj-hun", "fatal_blow-dgjj-hun",
                "cd-dgjj-hun", "ap_power-dgjj-xiao", "da_power-dgjj-xiao", "fatal_blow-dgjj-xiao",
        }),

        "桃花島": ({
                "dodgeup-luoying-shenfa", "parryup-yuxiao-jianfa", "parryup-tanzhi-shentong", "ap_power-yxjf-bihai", "da_power-yxjf-bihai",
                "ap_power-tzst-dian", "da_power-tzst-dian", "cd-tzst-dian", "ap_power-tzst-zhuan", "da_power-tzst-zhuan", "cd-tzst-lingxi",
        }),

        "歐陽世家":({
                "dodgeup-chanchu-bufa", "parryup-hamagong", "powerup-hmg-reserve", "ap_power-hmg-zhen", "da_power-hmg-zhen",
                "cd-hmg-nizhuan",
        }),

        "段氏皇族":({
                "full-krcg-kurong", "dodgeup-tiannan-bu", "parryup-six-finger", "ap_power-lmsj-gz", "da_power-lmsj-gz",
                "ap_power-lmsj-tian", "da_power-lmsj-tian", "cd-lmsj-tian", "ap_power-yyz-die", "da_power-yyz-die",
                "ap_power-yyz-jian", "da_power-yyz-jian",
        }),

        "丐幫"  : ({
                "dodgeup-feiyan-zoubi", "parryup-dragon-strike", "ap_power-dgb-tian", "ap_power-xlsbz-hui", "da_power-xlsbz-hui",
                "double_damage-xlsbz-hui","ap_power-xlsbz-long", "da_power-xlsbz-long", "double_damage-xlsbz-long", "cd-xlsbz-long",
        }),

        "全真教": ({
                "dodgeup-jinyan-gong", "parryup-kongming-quan", "ap_power-hubo", "ap_power-xtg-xian", "da_power-xtg-xian", "cd-xtg-xian",
                "ap_power-xtg-jian", "da_power-xtg-jian", "ap_power-xtg-shen", "da_power-xtg-shen",
        }),

        "古墓派": ({
                "powerup-nhkt-haixiao", "dodgeup-yunv-shenfa", "parryup-xuantie-jian", "parryup-sad-strike", "parryup-yunv-jian", "ap_power-hubo",
                "ap_power-arxhz-tuo", "da_power-arxhz-tuo", "cd-arxhz-tuo", "cd-ynxf-wuzhi",
        }),

        "明教"  : ({
                "dodgeup-qingfu-shenfa", "parryup-qiankun-danuoyi", "ap_power-jysg-ri", "da_power-jysg-ri", "cd-jysg-ri",
                "ap_power-qkdny-yi", "da_power-qkdny-yi", "cd-qkdny-nuozhuan", "power-qkdny-nuozhuan", "ap_power-shl-can",
        }),

        "魔教"  : ({
                "powerup-cykzj-huaxue", "dodgeup-jiutian-xiaoyaobu", "parryup-moshen-zhenshen", "ap_power-tymyd-mingyue", "da_power-tymyd-mingyue",
                "ap_power-yywd-ting", "da_power-yywd-ting", "fatal_blow-yywd-ting", "ap_power-yywd-dao", "da_power-yywd-dao",
                "fatal_blow-yywd-dao", "cd-yywd-ting", "cd-yywd-dao",
        }),

        "日月神教":({
                "powerup-rygh-richu", "dodgeup-pixie-jian", "parryup-pixie-jian", "add-khxf-sneaky", "ap_power-pxj-you",
                "da_power-pxj-you", "powerup-pxj-jian",
        }),

        "星宿派": ({
                "powerup_hgdf-suck", "dodgeup-feixing-shu", "parryup-chousui-zhang", "ap_power-csz-shi", "da_power-csz-shi", "ap_power-csz-tao",
                "da_power-csz-tao", "cd-freezing-hanmo",
        }),

        "逍遙派": ({
                "powerup-bmsg-suck", "dodgeup-lingbo-weibu", "parryup-liuyang-zhang", "parryup-zhemei-shou", "cd-lbwb-shen", "ap_power-lyz-hui",
                "da_power-lyz-hui", "ap_power-zms-hua", "da_power-zms-hua",
        }),

        "靈鷲宮": ({
                "dodgeup-yueying-wubu", "parryup-liuyang-zhang", "ap_power-lyz-zhen", "da_power-lyz-zhen", "ap_power-lyz-zun", "da_power-lyz-zun",
                "cd-bhg-protect",
        }),

        "神龍教": ({
                "dodgeup-yixing-bufa", "parryup-shedao-qigong", "ap_power-bssl-zhou", "ap_power-sdqg-xian", "da_power-sdqg-xian",
                "ap_power-sdqg-hou", "da_power-sdqg-hou",
        }),

        "血刀門": ({
                "powerup-xhmg-jixue", "dodgeup-shenkong-xing", "parryup-xuedao-daofa", "ap_power-xddf-xue", "da_power-xddf-xue",
                "ap_power-szj-ying", "da_power-szj-ying", "ap_power-xddf-huan", "da_power-xddf-huan", "cd-xddf-huan",
        }),

        "雪山寺": ({
                "dodgeup-shenkong-xing", "parryup-longxiang-gong", "ap_power-lxbrg-zhen", "da_power-lxbrz-zhen", "ap_power-ryl-lian",
                "ap_power-lxbrg-longxiang", "da_power-lxbrg-longxiang", "cd-lxbrg-longxiang",
        }),

        "密宗": ({
                "powerup-xhmg-jixue", "dodgeup-shenkong-xing", "parryup-xuedao-daofa", "ap_power-xddf-xue", "da_power-xddf-xue",
                "ap_power-szj-ying", "da_power-szj-ying", "ap_power-xddf-huan", "da_power-xddf-huan", "cd-xddf-huan",
                "dodgeup-shenkong-xing", "parryup-longxiang-gong", "ap_power-lxbrg-zhen", "da_power-lxbrz-zhen", "ap_power-ryl-lian",
                "ap_power-lxbrg-longxiang", "da_power-lxbrg-longxiang", "cd-lxbrg-longxiang",
        }),

        "五毒教": ({
                "dodgeup-wudu-yanluobu", "ap_power-wdsg-arrow", "parryup-qianzhu-wandushou", "ap_power-qzwds-chuan", "da_power-qzwds-chuan",
                "ap_power-qzwds-qzwd", "da_power-qzwds-qzwd", "cd-qzwds-qzwd", 
                "cd-bdjcg-summon", "max-bdjcg-summon", "chance-bdjcg-protect", "n-bdjcg-grow1", "n--bdjcg-grow2", 
                "cd-bdjcg-wpin", "ap_power-bdjcg-wpin", "da_power-bdjcg-wpin", "da_power-bdjcg-wpin2", "da_power-bdjcg-wpin3",
                "chance-bdjcg-cpin", "hp-bdjcg", "reduce_damage-bdjcg", "avoid_die-bdjcg",
        }),

        "關外胡家":({
                "dodgeup-sixiang-bufa", "parryup-daojian-guizhen", "defdown-lengyue", "ap_power-hjdf-pi", "da_power-hjdf-pi",
                "ap_power-djgz-tian", "da_power-djgz-tian", "ap_power-djgz-jiu", "da_power-djgz-jiu", "cd-djgz-jiu",
                "power-msqd-despel",
        }),

        "慕容世家":({
                "dodgeup-beidou-xianzong", "parryup-douzhuan-xingyi", "ap_power-chz-canhe", "da_power-chz-canhe",
                "ap_power-dzxy-yi", "cd-dzxy-yi",
        }),

        "唐門世家":({
                "dodgeup-qiulin-sheye", "parryup-boyun-suowu", "ap_power-tmaq-san", "da_power-tmaq-san",
                "ap_power-tmaq-hua", "da_power-tmaq-hua", "ap_power-tmaq-shijie", "cd-tmaq-shijie",
        }),
]);

mapping fam_ability_info = ([
// 命中，傷害，躲閃，招架，減CD, 特殊效果時間持續，暴擊幾率，致命一擊
// 冰凍效果，忙亂，遺忘，虛弱
        "少林派": ({
                "少林身法閃避機會＋５％\t",
                "金剛不壞體招架機會＋５％",
                "金剛不壞CD時間減少５秒\t",
                "佛光普照CD時間減少５秒\t",
                "傷字訣命中機會＋５％\t",
                "傷字訣傷害力＋５％\t",
                "六道輪迴命中機會＋５％\t",
                "六道輪迴傷害力＋５％\t",
                "六道輪迴CD時間減少５秒\t",
        }),

        "武當派": ({
                "梯雲縱閃避機會＋５％\t",
                "太極拳招架機會＋５％\t",
                "太極劍招架機會＋５％\t",
                "太極圖命中機會＋５％\t",
                "太極圖傷害力＋５％\t",
                "太極圖CD時間減少５秒\t",
                "真武除邪命中機會＋５％\t",
                "真武除邪傷害力＋５％\t",
                "太極劍意命中機會＋５％\t",
                "太極劍意傷害力＋５％\t",
                "太極劍意CD時間減少５秒\t",
        }),

        "峨嵋派"  : ({
                "諸天化身步閃避機會＋５％",
                "飄雪穿雲掌招架機會＋５％",
                "佛光普照命中機會＋５％\t",
                "迴風拂柳劍招架機會＋５％",
                "絕劍命中機會＋５％\t",
                "絕劍傷害力＋５％\t",
                "鳳凰涅磐CD時間減少５秒\t",
        }),

        "華山派": ({
                "紫氣東來加持傷害效果＋５％",
                "飛燕迴翔閃避機會＋５％\t",
                "獨孤九劍無招特防機會＋５％",
                "劍魂命中機會＋５％\t",
                "劍魂傷害力＋５％\t",
                "劍魂追加致命一擊觸發幾率＋５％",
                "劍魂CD時間減少５秒\t",
                "滄海笑命中機會＋５％\t",
                "滄海笑傷害力＋５％\t",
                "滄海笑追加致命一擊觸發幾率＋５％",
        }),

        "桃花島": ({
                "落英身法閃避機會＋５％\t",
                "玉簫劍法招架機會＋５％\t",
                "彈指神通招架機會＋５％\t",
                "碧海潮生按玉簫命中機會＋５％",
                "碧海潮生按玉簫傷害力＋５％",
                "隔空點穴命中機會＋５％\t",
                "隔空點穴傷害力＋５％\t",
                "隔空點穴CD時間減少５秒\t",
                "轉乾坤命中機會＋５％\t",
                "轉乾坤傷害力＋５％\t",
                "靈犀一指CD時間減少５秒\t",
        }),

        "歐陽世家": ({
                "蟾蜍步法閃避機會＋５％\t",
                "蛤蟆功招架機會＋５％\t",
                "經脈倒轉加持攻防效果＋５％",
                "蟾震九天命中機會＋５％\t",
                "蟾震九天命傷害力＋５％\t",
                "逆轉九陰CD時間減少５秒\t",
        }),

        "段氏皇族": ({
                "枯榮心法的回血效果＋５％",
                "天南步法閃避機會＋５％\t",
                "六脈神劍招架機會＋５％\t",
                "六脈歸宗命中機會＋５％\t",
                "六脈歸宗傷害力＋５％\t",
                "天脈神劍命中機會＋５％\t",
                "天脈神劍傷害力＋５％\t",
                "天脈神劍CD時間減少５秒\t",
                "陽關三疊命中機會＋５％\t",
                "陽關三疊傷害力＋５％\t",
                "先天功乾陽劍氣命中機會＋５％",
                "先天功乾陽劍氣傷害力＋５％",
        }),

        "丐幫"  : ({
                "飛簷走壁閃避機會＋５％\t",
                "降龍十八掌招架機會＋５％",
                "天下無狗命中機會＋５％\t",
                "亢龍有悔命中機會＋５％\t",
                "亢龍有悔傷害力＋５％\t",
                "亢龍有悔追加暴擊觸發幾率＋５％",
                "龍嘯九天命中機會＋５％\t",
                "龍嘯九天傷害力＋５％\t",
                "龍嘯九天追加暴擊觸發幾率＋５％",
                "龍嘯九天CD時間減少５秒\t",
        }),

        "全真教": ({
                "金雁功閃避機會＋５％\t",
                "空明拳招架機會＋５％\t",
                "左右互博的命中＋５％\t",
                "先天罡氣命中機會＋５％\t",
                "先天罡氣傷害力＋５％\t",
                "先天罡氣CD時間減少５秒\t",
                "先天功乾陽劍氣命中機會＋５％",
                "先天功乾陽劍氣傷害力＋５％",
                "純陽神通功命中機會＋５％",
                "純陽神通功傷害力＋５％\t",
        }),

        "古墓派": ({
                "海天一嘯效果＋５％\t",
                "玉女身法閃避機會＋５％\t",
                "玄鐵劍法招架機會＋５％\t",
                "黯然銷魂掌招架機會＋５％",
                "玉女劍法招架機會＋５％\t",
                "左右互博的命中＋５％\t",
                "拖泥帶水命中機會＋５％\t",
                "拖泥帶水傷害力＋５％\t",
                "拖泥帶水CD時間減少５秒\t",
                "所向無滯CD時間減少５秒\t",
        }),

        "明教"  : ({
                "青蝠身法閃避機會＋５％\t",
                "乾坤大挪移招架機會＋５％",
                "魔光日無極命中機會＋５％",
                "魔光日無極傷害力＋５％\t",
                "魔光日無極CD時間減少５秒",
                "大挪移命中機會＋５％\t",
                "大挪移傷害力＋５％\t",
                "挪轉乾坤CD時間減少５秒\t",
                "挪轉乾坤反傷效果＋５％\t",
                "殘血令命中機會＋５％\t",
        }),

        "魔教"  : ({
                "神刀化血加持傷害效果＋５％",
                "九天逍遙步閃避機會＋５％",
                "魔神真身招架機會＋５％\t",
                "天涯明月命中機會＋５％\t",
                "天涯明月傷害力＋５％\t",
                "小樓一夜聽春雨命中機會＋５％",
                "小樓一夜聽春雨傷害力＋５％",
                "小樓一夜聽春雨追加致命一擊觸發幾率＋５％",
                "刀至上-至上刀命中機會＋５％",
                "刀至上-至上刀傷害力＋５％",
                "刀至上-至上刀追加致命一擊觸發幾率＋５％",
                "小樓一夜聽春雨群傷CD時間減少５秒",
                "刀至上-至上刀CD時間減少５秒",
        }),

        "日月神教":({
                "日出東方加持傷害效果＋５％",
                "辟邪劍閃避機會＋５％\t",
                "辟邪劍招架機會＋５％\t",
                "鬼隱時間＋５秒\t",
                "幽冥一擊命中機會＋５％\t",
                "幽冥一擊傷害力＋５％\t",
                "辟邪劍影命中及傷害＋５％",
        }),

        "星宿派": ({
                "化工大法吸取內力效果＋５％",
                "飛星術閃避機會＋５％\t",
                "抽髓掌招架機會＋５％\t",
                "腐屍毒命中機會＋５％\t",
                "腐屍毒傷害力＋５％\t",
                "碧焰滔天命中機會＋５％\t",
                "碧焰滔天傷害力＋５％\t",
                "寒魔玄力CD時間減少５秒\t",
        }),

        "逍遙派": ({
                "北冥神功吸取內力效果＋５％",
                "凌波微步閃避機會＋５％\t",
                "天山六陽掌招架機會＋５％",
                "折梅手招架機會＋５％\t",
                "神光離合CD時間減少５秒\t",
                "灰飛湮滅命中機會＋５％\t",
                "灰飛湮滅傷害力＋５％\t",
                "化妖功命中機會＋５％\t",
                "化妖功傷害力＋５％\t",
        }),

        "靈鷲宮": ({
                "月影舞步閃避機會＋５％\t",
                "天山六陽掌招架機會＋５％",
                "一掌震天命中機會＋５％\t",
                "一掌震天傷害力＋５％\t",
                "八荒獨尊掌命中機會＋５％",
                "八荒獨尊掌傷害力＋５％\t",
                "八荒獨尊掌CD時間減少５秒",
                "唯我獨尊CD時間減少５秒\t",
        }),

        "神龍教": ({
                "意形步法閃避機會＋５％\t",
                "蛇島奇功招架機會＋５％\t",
                "咒法命中機會＋５％\t",
                "神龍再現命中機會＋５％\t",
                "神龍再現傷害力＋５％\t",
                "吼字決命中機會＋５％\t",
                "吼字決傷害力＋５％\t",
        }),

        "血刀門": ({
                "祭血大法加持傷害效果＋５％",
                "身空行閃避機會＋５％\t",
                "血刀刀法招架機會＋５％\t",
                "噬血穹蒼命中機會＋５％\t",
                "噬血穹蒼傷害力＋５％\t",
                "無影神拳命中機會＋５％\t",
                "無影神拳傷害力＋５％\t",
                "我必還之命中機會＋５％\t",
                "我必還之傷害力＋５％\t",
                "我必還之CD時間減少５秒\t",
        }),

        "雪山寺": ({
                "身空行閃避機會＋５％\t",
                "龍象般若功招架機會＋５％",
                "真·般若極命中機會＋５％",
                "真·般若極傷害力＋５％\t",
                "五輪連轉命中和傷害＋５％",
                "十龍十象命中機會＋５％\t",
                "十龍十象傷害力＋５％\t",
                "十龍十象CD時間減少５秒\t",
        }),

        "密宗": ({
                "祭血大法加持傷害效果＋５％",
                "身空行閃避機會＋５％\t",
                "血刀刀法招架機會＋５％\t",
                "噬血穹蒼命中機會＋５％\t",
                "噬血穹蒼傷害力＋５％\t",
                "無影神拳命中機會＋５％\t",
                "無影神拳傷害力＋５％\t",
                "我必還之命中機會＋５％\t",
                "我必還之傷害力＋５％\t",
                "我必還之CD時間減少５秒\t",
                "身空行閃避機會＋５％\t",
                "龍象般若功招架機會＋５％",
                "真·般若極命中機會＋５％",
                "真·般若極傷害力＋５％\t",
                "五輪連轉命中和傷害＋５％",
                "十龍十象命中機會＋５％\t",
                "十龍十象傷害力＋５％\t",
                "十龍十象CD時間減少５秒\t",
        }),

        "五毒教": ({
                "五毒煙蘿步閃避機會＋５％",
                "碧血箭命中機會＋５％\t",
                "千蛛萬毒手招架機會＋５％",
                "萬毒穿心命中機會＋５％\t",
                "萬毒穿心傷害力＋５％\t",
                "千蛛萬毒命中機會＋５％\t",
                "千蛛萬毒傷害力＋５％\t",
                "千蛛萬毒CD時間減少５秒\t",
                "金蠶蠱召喚CD時間減半\t",
                "金蠶蠱最大召喚數＋０.５\t",
                "金蠶蠱護主機會＋５％\t",
                "金蠶蠱成長速度＋１０％\t",
                "金蠶蠱成長速度再＋１０％\t",
                "金蠶蠱白針CD時間減少１秒\t",
                "金蠶蠱白針命中機會＋５％\t",
                "金蠶蠱白針傷害力＋５％\t",
                "金蠶蠱針對NPC傷害力＋５０％\t",
                "金蠶蠱針對NPC傷害力再＋２５％\t",
                "金蠶蠱彩針觸發機會提高\t",
                "金蠶蠱的ＨＰ提升２０％\t",
                "金蠶蠱減免傷害的能力翻倍\t",
                "金蠶蠱死亡豁免的幾率提高\t",
        }),

        "關外胡家":({
                "四象步法閃避機會＋５％\t",
                "刀劍歸真招架機會＋５％\t",
                "冷月寒氣影響對手閃避－５％",
                "開天劈地命中機會＋５％\t",
                "開天闢地傷害力＋５％\t",
                "刀劍七重天命中機會＋５％",
                "刀劍七重天傷害力＋５％\t",
                "刀劍九重天命中機會＋５％",
                "刀劍九重天傷害力＋５％\t",
                "刀劍九重天CD時間減少５秒",
                "妙手驅毒效果＋５％\t",
        }),

        "慕容世家":({
                "北斗仙蹤閃避機會＋５％\t",
                "斗轉星移招架機會＋５％\t",
                "參合劍氣命中機會＋５％\t",
                "參合劍氣傷害力＋５％\t",
                "斗轉星移命中機會＋５％\t",
                "斗轉星移CD時間減少５秒\t",
        }),

        "唐門世家":({
                "秋林拾葉閃避機會＋５％\t",
                "撥雲鎖霧招架機會＋５％\t",
                "散花天女命中機會＋５％\t",
                "散花天女傷害力＋５％\t",
                "唐花命中機會＋５％\t",
                "唐花傷害力＋５％\t\t",
                "一花一世界命中機會＋５％",
                "一花一世界CD時間減少５秒",
        }),
]);

string *talent_ability = ({
        "research_effect",
        "derive_effect",
        "practice_effect",
        "add_exp",
        "magic_find",
        "add_con",
        "qi_recover",
        "jing_recover",
        "neili_recover",
        "avoid_boss_perform",
        "add_boss_defense",
        "add_boss_damage",
        "attack",
        "parry",
        "dodge",
        "double_damage",
        "avoid_dodge",
        "reduce_cd",
        "avoid_busy",
        "avoid_weak",
        "add_damage",
        "reduce_damage",
        "add_forget",
        "avoid_pot_penalty",
        "powerup_blade",
        "powerup_sword",
        "powerup_unarmed",
        "powerup_throwing",
        "powerup_poison",
        "avoid_die",
        "full_self",
        "fatal_blow",
});

mapping max_talent_ability = ([
        "research_effect" : 1,
        "derive_effect"   : 1,
        "practice_effect" : 1,
        "add_exp"         : 2,
        "magic_find"      : 2,
        "add_con"         : 2,
        "qi_recover"      : 3,
        "jing_recover"    : 2,
        "neili_recover"   : 2,
        "avoid_boss_perform" : 3,
        "add_boss_defense"   : 4,
        "add_boss_damage"    : 3,
        "attack"          : 3,
        "parry"           : 3,
        "dodge"           : 3,
        "double_damage"   : 5,
        "avoid_dodge"     : 5,
        "reduce_cd"       : 2,
        "avoid_busy"      : 3,
        "avoid_weak"      : 3,
        "add_damage"      : 5,
        "reduce_damage"   : 3,
        "add_forget"      : 3,
        "avoid_pot_penalty"  : 5,
        "powerup_blade"   : 5,
        "powerup_sword"   : 5,
        "powerup_unarmed" : 5,
        "powerup_throwing" : 5,
        "powerup_poison" : 5,
        "avoid_die"       : 5,
        "full_self"       : 5,
        "fatal_blow"      : 5,
]);

mapping talent_ability_data = ([
        "research_effect" : 20,
        "derive_effect"   : 20,
        "practice_effect" : 20,
        "add_exp"         : 5,
        "magic_find"      : 5,
        "add_con"         : 5,
        "qi_recover"      : 10,
        "jing_recover"    : 10,
        "neili_recover"   : 10,
        "avoid_boss_perform" : 10,
        "add_boss_defense"   : 5,
        "add_boss_damage"    : 5,
        "attack"          : 3,
        "parry"           : 3,
        "dodge"           : 3,
        "double_damage"   : 4,
        "avoid_dodge"     : 4,
        "reduce_cd"       : 5,
        "avoid_busy"      : 3,
        "avoid_weak"      : 3,
        "add_damage"      : 4,
        "reduce_damage"   : 5,
        "add_forget"      : 3,
        "avoid_pot_penalty"  : 5,
        "powerup_blade"   : 4,
        "powerup_sword"   : 4,
        "powerup_unarmed" : 4,
        "powerup_throwing" : 4,
        "powerup_poison" : 4,
        "avoid_die"       : 2,
        "full_self"       : 2,
        "fatal_blow"      : 2,
]);

string *talent_ability_info = ({
        "神研：研究效率提高20%",
        "神思：汲取效率提高20%",
        "神練：練習效率提高20%",
        "神蘊：任務中獲取經驗額外增加5%、10%點",
        "神運：裝備掉落幾率增加5%、10%點",
        "神佑：門派貢獻額外增加5%、10%點",
        "戰神：戰鬥時自動恢復氣血速度提高10%、20%、30%",
        "戰靈：戰鬥時自動恢復精氣速度10%、20%",
        "戰狂：戰鬥中自動恢復內力速度10%、20%",
        "明鏡：使玩家有10%、20%、30%的幾率防止怪物的必殺技",
        "金剛：增加對boss怪物的絕對防禦5%、10%點、15%、20%",
        "伏魔：增加對boss怪物的絕對傷害5%、10%點、15%點",
        "鷹眼：命中增加3%、6%、9%",
        "格擋：招架增加3%、6%、9%",
        "迷蹤：躲閃增加3%、6%、9%",
        "暴擊：雙倍傷害幾率增加4%、8%、12%、16%、20%",
        "強襲：4%、8%、12%、16%、20%的機率讓輕功的特殊防禦均無效",
        "歸真：特殊武功大招的冷卻時間降低5秒、10秒",
        "逍遙：戰鬥中有3%、6%、9%的機率消除忙亂",
        "武神：增加抵抗虛弱能力3%、6%、9%",
        "極境：增加4%、8%、12%、16%、20%的傷害效果",
        "守護：減少5%、10%、15%的傷害效果",
        "遺忘：讓對手有3%、6%、9%的幾率遺忘絕招",
        "天賜：死亡時有5%、10%、15%、20%、25%的機率不掉潛能",
        "刀皇：使用刀法武功增加4%、8%、12%、16%、20%的命中及傷害",
        "劍聖：使用劍法武功增加4%、8%、12%、16%、20%的命中及傷害",
        "拳王：使用拳法武功增加4%、8%、12%、16%、20%的命中及傷害",
        "飛仙：使用暗器技能增加4%、8%、12%、16%、20%的命中及傷害",
        "毒君：增加4%、8%、12%、16%、20%的幾率破除怪體等對毒的免疫",
        "涅槃：忽視死亡的幾率提高2%、4%、6%、8%、10%",
        "神戰：氣血內力自動恢復幾率提高2%、4%、6%、8%、10%",
        "神殺：戰鬥中造成致命一擊的幾率提高2%、4%、6%、8%、10%",
});

int do_ability_cost(object ob, string arg, int flag);
int check_ability(object me,string arg, int flag);
int check_ability_count(object me,string arg, int flag);
int improve_ability(object me,string arg, int flag);
int valid_ability_improve(object me, string arg, int flag);
string get_ability_idf(object me,string arg, int flag);
string get_ability_info(object ob, string arg, int flag);

int valid_ability_improve(object me, string arg, int flag)
{
        int level;
        int a_lvl;
        int u_lvl;

        a_lvl = check_ability_count(me, arg, flag);
        if( flag == 2 )
                level = max_talent_ability[arg];
        else
                level = max_ability[arg];
        if( !level ) level = 5;
        if( a_lvl >= level )
                return 0;

        u_lvl = query("level", me);
        if( flag == 0 && u_lvl < 10 ) {
                return 0;
        }
        if( flag == 1 && u_lvl < 20 ) {
                return 0;
        }
        if( flag == 2 ) {
                return 1;
        }

        return 1;
}

varargs int check_ability(object me,string arg, int flag)
{
        int result;

        if( flag == 2 )
                // 天賦技能
                result = query("talent/" + arg, me);
        else
                // Ability 門派
                result=query("ability2/"+query("family/family_name", me)+"/"+arg, me)+query("ability1/"+arg, me);

        return result;
}

varargs int check_ability_count(object me,string arg, int flag)
{
        int result;

        if( flag == 2 )
                // 天賦技能
                result = query("talent_count/" + arg, me);
        else
                // Ability 門派
                result=query("ability_count/"+me->query_family()+"/"+arg, me)+query("ability_count/"+arg, me);

        return result;
}

int check_ability_cost(object me, string arg, int flag)
{
        int cost;

        if( flag == 1 ) {
                if( !undefinedp(fam_ability_pot[arg]) )
                        cost = fam_ability_pot[arg];
                else
                        cost = 5;
        } else if( flag == 2 ) {
                cost = 1;
        } else {
                if( member_array(arg, bas_ability) == -1 ) {
                        return 0;
                }
                cost = bas_ability_pot[arg];
                if( !cost ) {
                        cost = 1;
                }
        }
        return cost;
}

// 每次耗費一點能力點及十萬點潛能
int do_ability_cost(object me, string arg, int flag)
{
        int cost, pot;

        cost = check_ability_cost(me, arg, flag);
        pot  = cost * 100000;
        if( query("potential", me) - query("learned_potential", me) < pot )
                return 0;

        if( flag == 1 || flag == 0 ) {
                if( cost > query("ability", me)-query("learned_ability", me) ) {
                        return 0;
                }
                addn("learned_ability", cost, me);
                addn("learned_potential", pot, me);
        }

        if( flag == 2 ) {
                if( cost > query("energy", me)-query("learned_energy", me) ) {
                        return 0;
                }
                addn("learned_energy", cost, me);
                addn("learned_potential", pot, me);
        }
        return 1;
}

int improve_ability(object me,string arg, int flag)
{
        int lv, n;
        string myclass;

        myclass = query("family/family_name", me);
        if( !flag ) {
                addn("ability1/"+arg, 1, me);
                addn("ability_count/"+arg, 1, me);
        } else if( flag == 1 ) {
                if( !undefinedp(fam_ability_data[arg]) )
                        n = fam_ability_data[arg];
                else
                        n = 5;
                addn("ability2/"+myclass+"/"+arg, n, me);
                addn("ability_count/"+myclass+"/"+arg, 1, me);
        } else if( flag == 2 ) {
                if( !undefinedp(talent_ability_data[arg]) )
                        n = talent_ability_data[arg];
                else
                        n = 1;
                addn("talent/"+arg, n, me);
                addn("talent_count/"+arg, 1, me);
        }
        return 1;
}

string get_ability_info(object ob, string arg, int flag)
{
        int lv, cost, n;
        string desc, msg, myclass;

        //lv = check_ability(ob, arg, flag);
        cost = check_ability_cost(ob, arg, flag);
        desc = get_ability_idf(ob,arg,flag);
        if( flag == 1 ) {
                // ability's 門派技能
                myclass=query("family/family_name", ob);
                if( arrayp(fam_ability[myclass]) ) {
                        n = member_array(arg,fam_ability[myclass]);
                        if( n != -1 ) {
                                msg = fam_ability_info[myclass][n];
                                msg = sprintf(msg+"\t%-12s"HIC"%5d\n"NOR,desc, cost);
                                return msg;
                        }
                }
                return "";
        }

        if( flag == 2 ) {
                n = member_array(arg,talent_ability);
                if( n != -1 ) {
                        msg = talent_ability_info[n];
                        msg = sprintf("%-60s%-12s"HIC"%5d\n"NOR, msg, desc, cost);
                        return msg;
                }
                return "";
        }

        n = member_array(arg, bas_ability);
        if( n != -1 ) {
                msg = bas_ability_info[n];
                msg = sprintf(msg+"\t%-12s"HIC"%5d\n"NOR, desc, cost);
                return msg;
        }
        return "";
}


string get_ability_idf(object me,string arg, int flag)
{
        int level;
        int lev = check_ability_count(me,arg,flag);
        // 1,2,3,4 Basic
        // 5,6,7 Advanced
        // 8,9: Master
        // 10: Grand Master
        string *tough_level_desc = ({
                BLU "一無所知" NOR,
                BLU "毫不足慮" NOR,
                BLU "不足掛齒" NOR,
                BLU "初學乍練" NOR,
                BLU "勉勉強強" NOR,
                HIB "初窺門徑" NOR,
                HIB "初出茅廬" NOR,
                HIB "略知一二" NOR,
                HIB "普普通通" NOR,
                HIB "平平淡淡" NOR,
                CYN "平淡無奇" NOR,
                CYN "粗通皮毛" NOR,
                CYN "半生不熟" NOR,
                CYN "馬馬虎虎" NOR,
                CYN "略有小成" NOR,
                HIC "已有小成" NOR,
                HIC "鶴立雞群" NOR,
                HIC "駕輕就熟" NOR,
                HIC "青出於藍" NOR,
                HIC "融會貫通" NOR,
                HIG "心領神會" NOR,
                HIG "爐火純青" NOR,
                HIG "瞭然於胸" NOR,
                HIG "略有大成" NOR,
                HIG "已有大成" NOR,
                YEL "豁然貫通" NOR,
                YEL "出類拔萃" NOR,
                YEL "無可匹敵" NOR,
                YEL "技冠群雄" NOR,
                YEL "神乎其技" NOR,
                HIY "出神入化" NOR,
                HIY "非同凡響" NOR,
                HIY "傲視群雄" NOR,
                HIY "登峰造極" NOR,
                HIY "無與倫比" NOR,
                RED "所向披靡" NOR,
                RED "一代宗師" NOR,
                RED "精深奧妙" NOR,
                RED "神功蓋世" NOR,
                RED "舉世無雙" NOR,
                WHT "驚世駭俗" NOR,
                WHT "撼天動地" NOR,
                WHT "震古鑠今" NOR,
                WHT "超凡入聖" NOR,
                WHT "威鎮寰宇" NOR,
                HIW "空前絕後" NOR,
                HIW "天人合一" NOR,
                MAG "深藏不露" NOR,
                HIM "深不可測" NOR,
                HIR "返璞歸真" NOR
        });
        string desc;

        if( flag == 2 )
                level = max_talent_ability[arg];
        else
                level = max_ability[arg];
        if( !level ) level = 5;

        desc = sprintf(HIM"%3d/%3d"NOR, lev, level);
        if( lev >= 10 ) lev = 10;
        return (tough_level_desc[lev]+"（"+ desc+"）");
}

/*
天賦系修改 設置，已完成幸運系。
攻擊系
絕世命中：降低對方對你所有物理攻擊的躲閃幾率！
極度殺戮：提升自己所有物理攻擊傷害！
嗜血元神：你有的幾率,在擊中對方後額外獲得一次額外物理攻擊擊！
防禦系
絕世招架：增加自己對所有物理攻擊的招架幾率！
極品體質：降低所有物理攻擊對你所造成傷害！
銅牆鐵壁：你有幾率,在被擊中後對敵人進行一次必中的物理攻擊;
文學系
絕世奇才：提高你百分之幾的讀書和學習效率
神童在世：提高你百分之幾的練習和研究效率
博學天才：你有百分之几几率,在技能升級時，使得這個技能;額外再升一級！
恢復系
絕世筋骨：提高你的運功療傷功效
死而後生：增加你在戰鬥中自動療傷效果
千古奇人：戰鬥中被擊中，自動恢復總氣血的並且 降低各類毒性發作時間。
幸運系
財神高照：獎勵你百分之幾的額外金錢數量！
福祿降世：獎勵你百分之幾的額外經驗、潛能、體會！
幸運大師：獎勵你百分之幾的額外英勇點數、境界修為點數、 仙石數目。遇到仙人、上古秘境、修真機緣、獲取極品物品、通過神陣等等的幾率更大。
*/

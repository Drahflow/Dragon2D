#include "Env.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "BaseClass.h"
#include "Ui.h"
#include "ScriptEngine.h"
#include "ScriptLibHelper.h"
#include "Sprite.h"
#include "Tileset.h"
#include "Map.h"

namespace Dragon2D {
	std::vector <std::function<void(void)>> gResetters;
	int StrToInt(std::string s) {
		return atoi(s.c_str());
	}
	float StrToFloat(std::string s) {
		return (float)atof(s.c_str());
	}


	void AddGlobalReset(std::function<void(void)> f) {
		gResetters.push_back(f);
	}

	void ResetGlobals() 
	{
		for (auto r : gResetters) {
			if (r) r();
		}
	}

	void LoadClasses(chaiscript::ChaiScript &chai) {
		SCRIPTFUNCTION_ADD(ScriptEngine::IncludeScript, "Include", chai);
		SCRIPTFUNCTION_ADD(ScriptEngine::RawEval, "RawEval", chai);
		SCRIPTTYPE_ADD(std::ostream, "ostream", chai);
		SCRIPTTYPE_ADD(TTF_Font, "TTF_Font", chai);
		SCRIPTTYPE_ADD(Mix_Chunk, "Mix_Chunk", chai);
		SCRIPTTYPE_ADD(GLuint, "GLuint", chai);
		//SCRIPTTYPE_ADD(GLfloat, "GLfloat", chai);
		SCRIPTFUNCTION_ADD(StrToInt, "StrToInt", chai);
		SCRIPTFUNCTION_ADD(StrToFloat, "StrToFloat", chai);
		SCRIPTFUNCTION_ADD(Env::Gamefile, "Gamefile", chai);
		SCRIPTFUNCTION_ADD(Env::Enginefile, "Enginefile", chai);
		SCRIPTFUNCTION_ADD(Env::GetCurrentMouseState, "Mouseinfo", chai);
		SCRIPTFUNCTION_ADD(Env::SwapBuffers, "UpdateScreen", chai);
		SCRIPTFUNCTION_ADD(Env::ClearFramebuffer, "ClearScreen", chai);
		SCRIPTFUNCTION_ADD(Env::ResetCurrentTextInput, "ResetCurrentTextInput", chai);
		SCRIPTFUNCTION_ADD(Env::GetCurrentText, "GetCurrentText", chai);
		SCRIPTCLASS_ADD(vec4, chai);
		SCRIPTCLASS_ADD(XMLUI, chai);
		SCRIPTCLASS_ADD(UIElement, chai);
		SCRIPTCLASS_ADD(BaseClass, chai);
		SCRIPTCLASS_ADD(Resource, chai);
		SCRIPTCLASS_ADD(AudioResource, chai);
		SCRIPTCLASS_ADD(VideoResource, chai);
		SCRIPTCLASS_ADD(TextureResource, chai);
		SCRIPTCLASS_ADD(ScriptResource, chai);
		SCRIPTCLASS_ADD(FontResource, chai);
		SCRIPTCLASS_ADD(GLProgramResource, chai);
		SCRIPTCLASS_ADD(MapResource, chai);
		SCRIPTCLASS_ADD(TextResource, chai);
		SCRIPTCLASS_ADD(ResourceManager, chai);
		SCRIPTCLASS_ADD(GameManager, chai);
		SCRIPTCLASS_ADD(Ui, chai);
		SCRIPTCLASS_ADD(Sprite, chai);
		SCRIPTCLASS_ADD(Tileset, chai);
		SCRIPTCLASS_ADD(BatchedTileset, chai);
		SCRIPTCLASS_ADD(Map, chai);
	}


	void ScriptInfo_vec4(chaiscript::ChaiScript&chai) {
		chaiscript::ModulePtr m = chaiscript::ModulePtr(new chaiscript::Module());
		m->add(chaiscript::user_type<glm::vec4>(), "vec4");
		m->add(chaiscript::constructor<glm::vec4()>(), "vec4");
		m->add(chaiscript::constructor<glm::vec4(const glm::vec4&)>(), "vec4");
		m->add(chaiscript::constructor<glm::vec4(float)>(), "vec4");
		m->add(chaiscript::constructor<glm::vec4(float, float, float, float)>(), "vec4");
		m->add(chaiscript::fun(&glm::vec4::x), "x");
		m->add(chaiscript::fun(&glm::vec4::y), "y");
		m->add(chaiscript::fun(&glm::vec4::z), "z");
		m->add(chaiscript::fun(&glm::vec4::w), "w");
		chai.add(m);
	}

	void ScriptInfo_XMLUI(chaiscript::ChaiScript&chai) {
		chaiscript::ModulePtr m = chaiscript::ModulePtr(new chaiscript::Module());
		m->add(chaiscript::user_type<TailTipUI::XMLLoader>(), "XMLUI");
		m->add(chaiscript::constructor<TailTipUI::XMLLoader(const TailTipUI::XMLLoader&)>(), "XMLUI");
		m->add(chaiscript::constructor<TailTipUI::XMLLoader(int, std::string)>(), "XMLUI");
		m->add(chaiscript::fun(&TailTipUI::XMLLoader::RenderElements), "RenderElements");
		m->add(chaiscript::fun(&TailTipUI::XMLLoader::GetElementById), "GetElementById");
		chai.add(m);
	}

	void ScriptInfo_UIElement(chaiscript::ChaiScript&chai) {
		chaiscript::ModulePtr m = chaiscript::ModulePtr(new chaiscript::Module());
		m->add(chaiscript::user_type<TailTipUI::GeneralElement>(), "UIElement");
		m->add(chaiscript::constructor<TailTipUI::GeneralElement()>(), "UIElement");
		m->add(chaiscript::constructor<TailTipUI::GeneralElement(const TailTipUI::GeneralElement&)>(), "UIElement");
		m->add(chaiscript::fun(&TailTipUI::GeneralElement::Render), "Render");
		m->add(chaiscript::fun(&TailTipUI::GeneralElement::SetHidden), "SetHidden");
		m->add(chaiscript::fun(&TailTipUI::GeneralElement::GetName), "GetName");
		m->add(chaiscript::fun(&TailTipUI::GeneralElement::SetName), "SetName");
		m->add(chaiscript::fun(&TailTipUI::GeneralElement::SetPos), "SetPosition");
		chai.add(m);
	}

}; //namespace Dragon2D
%{Cpp:LicenseTemplate}\
#ifndef %{GUARD}
#define %{GUARD}

@if '%{Base}' === 'LogicComponent'
#include <Urho3D/Scene/LogicComponent.h>
@elsif '%{Base}' === 'Component'
#include <Urho3D/Scene/Component.h>
@endif
#include <Urho3D/Scene/Node.h>

using namespace Urho3D;

%{JS: Cpp.openNamespaces('%{Class}')}
@if '%{Base}'
class %{CN} : public %{Base}
@else
class %{CN}
@endif
{
	URHO3D_OBJECT(%{CN}, %{Base});
public:
@if '%{Base}' === 'Drawable'
	%{CN}(Context* context, unsigned char drawableFlags);
@else	
	%{CN}(Context* context);
@endif
@if '%{Base}' === 'LogicComponent'
    static void RegisterObject(Context* context);
    virtual void OnNodeSet(Node* node);
    virtual void Update(float timeStep);
@endif
};
%{JS: Cpp.closeNamespaces('%{Class}')}
#endif // %{GUARD}\

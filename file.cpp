%{Cpp:LicenseTemplate}\
#include "%{HdrFileName}"
%{JS: Cpp.openNamespaces('%{Class}')}

@if '%{Base}' === 'Drawable'
%{CN}::%{CN}(Context* context, unsigned char drawableFlags) : Drawable(context, drawableFlags)
@elsif '%{Base}'
%{CN}::%{CN}(Context* context) : %{Base}(context)
@else
%{CN}::%{CN}()
@endif
{
@if '%{Base}' === 'LogicComponent'
SetUpdateEventMask(USE_UPDATE);
@endif
}
@if '%{Base}' === 'LogicComponent' || '%{Base}' === 'Component'

void %{CN}::OnNodeSet(Node* node) {
}

void %{CN}::Update(float timeStep)
{
}
@endif
%{JS: Cpp.closeNamespaces('%{Class}')}\

#include "\syzygy\refinery\process_state\process_state_util.h"
#include "\syzygy\refinery\process_state\process_state_util.cc"
#include "\syzygy\refinery\process_state\process_state.cc"
#include "\syzygy\refinery\process_state\process_state.h"
#include "\syzygy\refinery\types\type.h"
#include "\syzygy\refinery\types\type.cc"
#include "\syzygy\refinery\types\type_repository.h"
#include "\syzygy\refinery\types\type_repository.cc"

void DataTypeExtracter()
{
TypeRepository type_object;
TypeId type_id_typerepo = data().type_id();  // neded to figure out if this is a right way to get typeid from the Typed block layer
TypePtr  type_pointer = type_object.GetType(CastTo(&type_id_typerepo)); // @p type_pointer a TypePtr pointer to point to Type class & here is the place which need to be figure out how to down cast the type we get. 

if (*type_pointer==USER_DEFINED_TYPE_KIND)
{
	Field field_object;
	FieldKind fieldkind_object;
	fieldkind_object = field_object.kind();
	if ( fieldkind_object == BASE_CLASS_KIND)
	{
			BaseClassField baseclass_object;
			TypeId baseclass_typeid = baseclass_object.Field.type_id();
			TypePtr baseclass_pointer = UserDefinedType::Field::GetType(CastTo(&baseclass_object)); //get the type of the base class kind
			ptrdiff_t baseclass_offset = baseclass_object.Field.offset;  // get the offset for the same kind
		
	}
    
}
};